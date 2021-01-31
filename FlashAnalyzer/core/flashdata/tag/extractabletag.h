#ifndef EXTRACTABLETAG_H
#define EXTRACTABLETAG_H

#include <string>
#include <QDataStream>

class ExtractableTag
{
public:
	virtual std::string extensionFile() const = 0;
	virtual void extract(QDataStream& outputStream) = 0;
};

#endif // EXTRACTABLETAG_H
