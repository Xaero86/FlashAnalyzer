#ifndef TAGSMODEL_H
#define TAGSMODEL_H

#include <QAbstractItemModel>

#include "swffile.h"
#include "definespritetag.h"

class TagsModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	TagsModel(QObject *parent);

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

public slots:
	void rowSelected(const QModelIndex &index);

signals:
	void tagSelected(Tag* tag);

private:
	SWFFile*        _swfFile;

	void addData(DefineSpriteTag *spriteTag, const QModelIndex &parent);
};

#endif // TAGSMODEL_H
