#ifndef EXTRACTABLEMODEL_H
#define EXTRACTABLEMODEL_H

#include <QAbstractItemModel>
#include <QList>

#include "swffile.h"
#include "definespritetag.h"

class ExtractableModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	ExtractableModel(QObject *parent);

	void setSwfData(SWFFile* swfFile);

	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
	bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &child) const override;

signals:
	void newImage(Tag* tag, QString& name, int index);
	void newVideo(Tag* tag, QString& name, int index);
	void newSound(Tag* tag, QString& name, int index);

private:
	SWFFile*        _swfFile;
	QList<Tag*>     _imageList;
	QList<Tag*>     _videoList;
	QList<Tag*>     _soundList;

	void scanSprite(DefineSpriteTag *spriteTag);
	static QString indexToType(int index)
	{
		switch (index) {
		case 0:
			return QString("Image");
		case 1:
			return QString("Video");
		case 2:
			return QString("Sound");
		default:
			return QString("");
		}
	}
};

#endif // EXTRACTABLEMODEL_H
