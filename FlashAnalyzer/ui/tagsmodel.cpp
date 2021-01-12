#include "tagsmodel.h"

TagsModel::TagsModel(QObject *parent)
	: QAbstractItemModel(parent),
	  _swfFile(nullptr)
{}

void TagsModel::setSwfData(SWFFile* swfFile)
{
	if (_swfFile != nullptr)
	{
		removeRows(0,_swfFile->tags().size());
		_swfFile = nullptr;
	}

	if (swfFile != nullptr)
	{
		_swfFile = swfFile;
		insertRows(0,_swfFile->tags().size());

		unsigned int rowIndex = 0;
		for (auto& tag : _swfFile->tags())
		{
			if (tag->code() == DEFINE_SPRITE_TAG)
			{
				DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>(tag.get());
				if (sprite)
				{
					addData(sprite, index(rowIndex, 0));
				}
			}
			rowIndex++;
		}
	}
}

void TagsModel::addData(DefineSpriteTag* spriteTag, const QModelIndex &parent)
{
	insertRows(0,spriteTag->tags().size(), parent);
	unsigned int rowIndex = 0;
	for (auto& tag : spriteTag->tags())
	{
		unsigned int tagCode = tag->code();
		if (tagCode == DEFINE_SPRITE_TAG)
		{
			DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>(tag.get());
			if (sprite)
			{
				addData(sprite, index(rowIndex, 0, parent));
			}
		}
		rowIndex++;
	}
}

int TagsModel::rowCount(const QModelIndex &parent) const
{
	if (!parent.isValid() && _swfFile != nullptr)
	{
		return (int) _swfFile->tags().size();
	}

	DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>((Tag*) parent.internalPointer());
	if (sprite)
	{
		return sprite->tags().size();
	}
	return 0;
}

int TagsModel::columnCount(const QModelIndex &/*parent*/) const
{
	return 1;
}

QVariant TagsModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || (_swfFile == nullptr))
	{
		return QVariant();
	}
	Tag* tag = (Tag*) index.internalPointer();
	if ((tag == nullptr) || (index.column() != 0))
	{
		return QVariant();
	}

	switch(role){
	case Qt::DisplayRole:
		return QString::fromStdString(tag->tagType());
		break;
	case Qt::BackgroundRole:
		return QVariant();
		break;
	case Qt::ForegroundRole:
		return QVariant();
		break;
	}

	return QVariant();
}

Qt::ItemFlags TagsModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return Qt::NoItemFlags;
	}
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

bool TagsModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row+count-1);
	endInsertRows();
	return true;
}

bool TagsModel::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row+count-1);
	endRemoveRows();
	return true;
}

bool TagsModel::hasChildren(const QModelIndex &parent) const
{
	return (rowCount(parent) > 0);
}

QModelIndex TagsModel::index(int row, int column, const QModelIndex &parent) const
{
	if ((_swfFile == nullptr) || (column != 0))
	{
		return QModelIndex();
	}

	Tag* result = nullptr;

	if (!parent.isValid())
	{
		if (row < (int) _swfFile->tags().size())
		{
			result = _swfFile->tags().at(row).get();
		}
	}
	else
	{
		DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>((Tag*) parent.internalPointer());
		if (sprite && (row < (int) sprite->tags().size()))
		{
			result = sprite->tags().at(row).get();
		}
	}
	return createIndex(row, 0, result);
}

QModelIndex TagsModel::parent(const QModelIndex &child) const
{
	if ((_swfFile == nullptr) || (!child.isValid()) || (child.internalPointer() == nullptr))
	{
		return QModelIndex();
	}

	Tag* childTag = (Tag*) child.internalPointer();
	if (childTag->parent() != nullptr)
	{
		DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>((Tag*) childTag->parent());
		if (sprite)
		{
			unsigned int rowIndex = 0;
			for (auto& tag : sprite->tags())
			{
				if (tag.get() == childTag)
				{
					return createIndex(rowIndex, 0, childTag->parent());
				}
				rowIndex++;
			}
		}
	}
	return QModelIndex();
}

void TagsModel::rowSelected(const QModelIndex &index)
{
	if (!index.isValid() || (_swfFile == nullptr))
	{
		return;
	}
	Tag* tag = (Tag*) index.internalPointer();
	if (tag != nullptr)
	{
		emit tagSelected(tag);
	}
}
