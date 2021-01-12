#include "extractablemodel.h"

ExtractableModel::ExtractableModel(QObject *parent)
	: QAbstractItemModel(parent),
	  _swfFile(nullptr)
{}

void ExtractableModel::setSwfData(SWFFile* swfFile)
{
	if (_swfFile != nullptr)
	{
		beginResetModel();
		_imageList.clear();
		_videoList.clear();
		_soundList.clear();
		endResetModel();
		_swfFile = nullptr;
	}

	if (swfFile != nullptr)
	{
		_swfFile = swfFile;
		insertRows(0,3);

		unsigned int rowIndex = 0;
		for (auto& tag : _swfFile->tags())
		{
			if (tag->isImage())
			{
				_imageList.push_back(tag.get());
			}
			if (tag->isVideo())
			{
				_videoList.push_back(tag.get());
			}
			if (tag->isSound())
			{
				_soundList.push_back(tag.get());
			}
			if (tag->code() == DEFINE_SPRITE_TAG)
			{
				DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>(tag.get());
				if (sprite)
				{
					scanSprite(sprite);
				}
			}
			rowIndex++;
		}

		insertRows(0, _imageList.size(), index(0, 0));
		insertRows(0, _videoList.size(), index(0, 1));
		insertRows(0, _soundList.size(), index(0, 2));
	}
}

void ExtractableModel::scanSprite(DefineSpriteTag *spriteTag)
{
	unsigned int rowIndex = 0;
	for (auto& tag : spriteTag->tags())
	{
		if (tag->isImage())
		{
			_imageList.push_back(tag.get());
		}
		if (tag->isVideo())
		{
			_videoList.push_back(tag.get());
		}
		if (tag->isSound())
		{
			_soundList.push_back(tag.get());
		}
		if (tag->code() == DEFINE_SPRITE_TAG)
		{
			DefineSpriteTag* sprite = dynamic_cast<DefineSpriteTag*>(tag.get());
			if (sprite)
			{
				scanSprite(sprite);
			}
		}
		rowIndex++;
	}
}

int ExtractableModel::rowCount(const QModelIndex &parent) const
{
	if (_swfFile == nullptr)
	{
		return 0;
	}
	if (!parent.isValid())
	{
		return 3;
	}
	if (!parent.parent().isValid() && (parent.row() == 0))
	{
		return _imageList.size();
	}
	if (!parent.parent().isValid() && (parent.row() == 1))
	{
		return _videoList.size();
	}
	if (!parent.parent().isValid() && (parent.row() == 2))
	{
		return _soundList.size();
	}
	return 0;
}

int ExtractableModel::columnCount(const QModelIndex &/*parent*/) const
{
	return 1;
}

QVariant ExtractableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || (index.column() != 0) || (_swfFile == nullptr))
	{
		return QVariant();
	}

	switch(role){
	case Qt::DisplayRole:
		if (!index.parent().isValid())
		{
			if (index.row() == 0)
			{
				return QString("Images");
			}
			if (index.row() == 1)
			{
				return QString("Video");
			}
			if (index.row() == 2)
			{
				return QString("Sounds");
			}
		}
		else
		{
			if (index.parent().row() == 0)
			{
				return QString("Image")+QString::number(index.row());
			}
			if (index.parent().row() == 1)
			{
				return QString("Video")+QString::number(index.row());
			}
			if (index.parent().row() == 2)
			{
				return QString("Sound")+QString::number(index.row());
			}
		}
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

Qt::ItemFlags ExtractableModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return Qt::NoItemFlags;
	}
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

bool ExtractableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	beginInsertRows(parent, row, row+count-1);
	endInsertRows();
	return true;
}

bool ExtractableModel::removeRows(int row, int count, const QModelIndex &parent)
{
	beginRemoveRows(parent, row, row+count-1);
	endRemoveRows();
	return true;
}

bool ExtractableModel::hasChildren(const QModelIndex &parent) const
{
	return (rowCount(parent) > 0);
}

QModelIndex ExtractableModel::index(int row, int column, const QModelIndex &parent) const
{
	if ((_swfFile == nullptr) || (column != 0))
	{
		return QModelIndex();
	}

	if (!parent.isValid())
	{
		return createIndex(row, 0, nullptr);
	}
	else
	{
		if ((parent.row() == 0) && (row < _imageList.size()))
		{
			return createIndex(row, 0, _imageList.at(row));
		}
		if ((parent.row() == 1) && (row < _videoList.size()))
		{
			return createIndex(row, 0, _videoList.at(row));
		}
		if ((parent.row() == 2) && (row < _soundList.size()))
		{
			return createIndex(row, 0, _soundList.at(row));
		}
	}
	return QModelIndex();
}

QModelIndex ExtractableModel::parent(const QModelIndex &child) const
{
	if ((_swfFile == nullptr) || (!child.isValid()) || (child.internalPointer() == nullptr))
	{
		return QModelIndex();
	}
	if (((Tag*) child.internalPointer())->isImage())
	{
		return createIndex(0, 0, nullptr);
	}
	if (((Tag*) child.internalPointer())->isVideo())
	{
		return createIndex(1, 0, nullptr);
	}
	if (((Tag*) child.internalPointer())->isSound())
	{
		return createIndex(2, 0, nullptr);
	}

	return QModelIndex();
}
