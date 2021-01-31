#ifndef DEFINEBITSTAG_H
#define DEFINEBITSTAG_H

#include "imagetag.h"
#include "jpegtablestag.h"

class DefineBitsTag : public ImageTag
{
public:
    DefineBitsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;

	void link(SWFFile* swfFile) override;

	void extract(QDataStream &outputStream) override;
	QImage toQImage() const override;

private:
	JPEGTablesTag* _tableTag;
};

#endif // DEFINEBITSTAG_H
