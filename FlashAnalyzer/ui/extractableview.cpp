#include "extractableview.h"

ExtractableView::ExtractableView(QWidget *parent)
	: QTreeView(parent)
{
	connect(this,SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(reqPreview()));
}

void ExtractableView::setModel(QAbstractItemModel *model)
{
	QTreeView::setModel(model);
	connect(selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),this,SLOT(selChanged()));
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
