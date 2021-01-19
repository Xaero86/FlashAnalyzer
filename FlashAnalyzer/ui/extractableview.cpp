#include "extractableview.h"

#include <QFileDialog>

#include "extractabletag.h"

ExtractableView::ExtractableView(QWidget *parent)
	: QTreeView(parent),
	_lastUsedPath(),
	_saveDialog(this,"Extract"),
	_saveAllDialog(this,"Extract all")
{
	setContextMenuPolicy(Qt::CustomContextMenu);

	_contextMenu = new QMenu(this);
	_actionExtract = new QAction("&Extract", this);
	_contextMenu->addAction(_actionExtract);

	_saveDialog.setFileMode(QFileDialog::AnyFile);
	_saveDialog.setAcceptMode(QFileDialog::AcceptSave);

	_saveAllDialog.setOption(QFileDialog::ShowDirsOnly);
	_saveAllDialog.setOption(QFileDialog::DontUseNativeDialog);
	_saveAllDialog.setFileMode(QFileDialog::Directory);
	_saveAllDialog.setAcceptMode(QFileDialog::AcceptSave);

	connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(prepareMenu(QPoint)));
	connect(_actionExtract,SIGNAL(triggered()),this,SLOT(handleExtract()));
	connect(this,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(reqPreview()));
}

void ExtractableView::setModel(QAbstractItemModel *model)
{
	QTreeView::setModel(model);
	connect(selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),this,SLOT(selChanged()));
}

void ExtractableView::setDefaultUrl(QUrl& url)
{
	if (_lastUsedPath.isEmpty())
	{
		_lastUsedPath = url;
	}
}

void ExtractableView::selectNext()
{
	QModelIndexList selecteds = selectedIndexes();

	if (selecteds.size() == 1)
	{
		QModelIndex selected = selecteds.at(0);
		if (!selected.isValid())
		{
			return;
		}
		if (!selected.parent().isValid())
		{
			return;
		}
		int row = selected.row();
		int max = model()->rowCount(selected.parent());
		QModelIndex nextIndex = selected.siblingAtRow((row+1)%max);
		selectionModel()->select(nextIndex, QItemSelectionModel::ClearAndSelect);
	}
}

void ExtractableView::selectPrevious()
{
	QModelIndexList selecteds = selectedIndexes();

	if (selecteds.size() == 1)
	{
		QModelIndex selected = selecteds.at(0);
		if (!selected.isValid())
		{
			return;
		}
		if (!selected.parent().isValid())
		{
			return;
		}
		int row = selected.row();
		int max = model()->rowCount(selected.parent());
		QModelIndex previousIndex = selected.siblingAtRow((row==0)?(max-1):(row-1));
		selectionModel()->select(previousIndex, QItemSelectionModel::ClearAndSelect);
	}
}

void ExtractableView::selChanged()
{
	QModelIndexList selecteds = selectedIndexes();

	if (selecteds.size() == 1)
	{
		QModelIndex selected = selecteds.at(0);
		if (!selected.isValid())
		{
			return;
		}
		Tag* tag = (Tag*) selected.internalPointer();
		if (tag != nullptr)
		{
			QString name = selected.data(Qt::DisplayRole).toString();
			emit tagSelected(tag, name);
		}
	}
}

void ExtractableView::reqPreview()
{
	QModelIndexList selecteds = selectedIndexes();

	if (selecteds.size() == 1)
	{
		QModelIndex selected = selecteds.at(0);
		if (selected.isValid() && selected.parent().isValid())
		{
			emit doubleClick(selected.parent().row());
		}
	}
}

void ExtractableView::prepareMenu(const QPoint &pos)
{
	QModelIndex element = indexAt(pos);

	if (element.isValid())
	{
		if (element.parent().isValid())
		{
			_actionExtract->setText("&Extract");
		}
		else
		{
			_actionExtract->setText("&Extract all");
		}
		_contextMenu->popup(viewport()->mapToGlobal(pos));
	}
}

void ExtractableView::handleExtract()
{
	QModelIndexList selecteds = selectedIndexes();

	if (selecteds.size() == 1)
	{
		QModelIndex selected = selecteds.at(0);
		if (!selected.isValid())
		{
			return;
		}
		if (!selected.parent().isValid())
		{
			_saveAllDialog.setDirectoryUrl(_lastUsedPath);

			int result = _saveAllDialog.exec();
			if ((result == QDialog::Accepted) && (_saveAllDialog.selectedUrls().size() == 1))
			{
				QUrl extractDir = _saveAllDialog.selectedUrls().at(0);
				if (!extractDir.isEmpty() && extractDir.isLocalFile())
				{
					QFileInfo fileInfo(extractDir.toLocalFile());
					_lastUsedPath = QUrl::fromLocalFile(fileInfo.filePath());

					for (int index = 0; index < model()->rowCount(selected); index++)
					{
						extractTag(model()->index(index,0,selected));
					}
				}
			}
		}
		else
		{
			Tag* tag = (Tag*) selected.internalPointer();
			ExtractableTag* extractable = dynamic_cast<ExtractableTag*>(tag);

			if (extractable)
			{
				QString defaultFileName = selected.data(Qt::DisplayRole).toString()+QString::fromStdString(extractable->extensionFile());
				QString filter = "File (*" + QString::fromStdString(extractable->extensionFile()) + ")";

				_saveDialog.setDirectoryUrl(_lastUsedPath);
				_saveDialog.setNameFilter(filter);
				_saveDialog.selectFile(defaultFileName);

				int result = _saveDialog.exec();
				if ((result == QDialog::Accepted) && (_saveDialog.selectedUrls().size() == 1))
				{
					QUrl extractFile = _saveDialog.selectedUrls().at(0);
					if (!extractFile.isEmpty() && extractFile.isLocalFile())
					{
						QFileInfo fileInfo(extractFile.toLocalFile());
						_lastUsedPath = QUrl::fromLocalFile(fileInfo.path());
						extractTag(selected, fileInfo.fileName());
					}
				}
			}
		}
	}
}

void ExtractableView::extractTag(const QModelIndex& index, QString fileName)
{
	Tag* tag = (Tag*) index.internalPointer();
	ExtractableTag* extractable = dynamic_cast<ExtractableTag*>(tag);
	if (extractable)
	{
		QString name = fileName;
		if (name.isNull())
		{
			name = index.data(Qt::DisplayRole).toString()+QString::fromStdString(extractable->extensionFile());
		}
		QString filePath = _lastUsedPath.toLocalFile() + "/" + name;
		std::ofstream file;
		file.open(filePath.toStdString().c_str(), std::fstream::binary);
		extractable->extract(file);
	}
}
