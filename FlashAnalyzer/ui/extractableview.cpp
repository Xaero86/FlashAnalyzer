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
	_actionPreview = new QAction("&Preview", this);
	_contextMenu->addAction(_actionPreview);

	_saveDialog.setFileMode(QFileDialog::AnyFile);
	_saveDialog.setAcceptMode(QFileDialog::AcceptSave);

	_saveAllDialog.setOption(QFileDialog::ShowDirsOnly);
	_saveAllDialog.setOption(QFileDialog::DontUseNativeDialog);
	_saveAllDialog.setFileMode(QFileDialog::Directory);
	_saveAllDialog.setAcceptMode(QFileDialog::AcceptSave);

	connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(prepareMenu(QPoint)));
	connect(_actionPreview,SIGNAL(triggered()),this,SLOT(reqPreview()));
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

void ExtractableView::selectImage(int pos)
{
	QModelIndex images = selectionModel()->model()->index(0,0);
	int max = selectionModel()->model()->rowCount(images);
	int index = pos % max;
	if (index < 0) index += max;
	QModelIndex newSel = selectionModel()->model()->index(index,0,images);
	selectionModel()->select(newSel, QItemSelectionModel::ClearAndSelect);
}

void ExtractableView::selectVideo(int pos)
{
	QModelIndex video = selectionModel()->model()->index(1,0);
	int max = selectionModel()->model()->rowCount(video);
	int index = pos % max;
	if (index < 0) index += max;
	QModelIndex newSel = selectionModel()->model()->index(index,0,video);
	selectionModel()->select(newSel, QItemSelectionModel::ClearAndSelect);
}

void ExtractableView::selectSound(int pos)
{
	QModelIndex sound = selectionModel()->model()->index(2,0);
	int max = selectionModel()->model()->rowCount(sound);
	int index = pos % max;
	if (index < 0) index += max;
	QModelIndex newSel = selectionModel()->model()->index(index,0,sound);
	selectionModel()->select(newSel, QItemSelectionModel::ClearAndSelect);
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
			switch (selected.parent().row()) {
			case 0:
				emit imageSelected(tag, name, selected.row());
				break;
			case 1:
				emit videoSelected(tag, name, selected.row());
				break;
			case 2:
				emit soundSelected(tag, name, selected.row());
				break;
			}
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
			switch (selected.parent().row()) {
			case 0:
				emit imagePreview();
				break;
			case 1:
				emit videoPreview();
				break;
			case 2:
				emit soundPreview();
				break;
			}
		}
	}
}

void ExtractableView::prepareMenu(const QPoint &pos)
{
	QModelIndex element = indexAt(pos);

	if (element.isValid())
	{
		if (element.parent().isValid() && (element.parent().row() < 2))
		{
			_actionExtract->setText("&Extract");
			_actionPreview->setVisible(true);
			_contextMenu->popup(viewport()->mapToGlobal(pos));
		}
		else if ((element.row() < 2) && (model()->hasChildren(element)))
		{
			_actionExtract->setText("&Extract all");
			_actionPreview->setVisible(false);
			_contextMenu->popup(viewport()->mapToGlobal(pos));
		}
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
		QFile outputFile(filePath);

		if (outputFile.open(QIODevice::WriteOnly))
		{
			QDataStream outStream(&outputFile);
			extractable->extract(outStream);
		}
	}
}
