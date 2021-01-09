#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>

class RectangleRecord
{
public:
    RectangleRecord() : _valid(false), _xMin(0), _xMax(0), _yMin(0), _yMax(0), _dataSize(0) {}
    
    void create(const char* source, uint32_t dataMax);
    
    bool valid() {return _valid;}
    uint32_t xMin() {return _xMin;}
    uint32_t xMax() {return _xMax;}
    uint32_t yMin() {return _yMin;}
    uint32_t yMax() {return _yMax;}
    uint32_t dataSize() {return _dataSize;}
    
private:
    bool          _valid;
    uint32_t      _xMin;
    uint32_t      _xMax;
    uint32_t      _yMin;
    uint32_t      _yMax;
    uint32_t      _dataSize;
};

class MatrixRecord
{
public:
    MatrixRecord() : _valid(false), 
                     _hasScale(false), _scaleX(0), _scaleY(0),
                     _hasRotate(false), _rotateSkew0(0), _rotateSkew1(0),
                     _translateX(0), _translateY(0), _dataSize(0) {}
    
    void create(const char* source, uint32_t dataMax);
    
    bool valid() {return _valid;}
    bool hasScale() {return _hasScale;}
    int32_t  scaleX() {return _scaleX;}
    int32_t  scaleY() {return _scaleY;}
    bool hasRotate() {return _hasRotate;}
    int32_t  rotateSkew0() {return _rotateSkew0;}
    int32_t  rotateSkew1() {return _rotateSkew1;}
    int32_t  translateX() {return _translateX;}
    int32_t  translateY() {return _translateY;}
    uint32_t dataSize() {return _dataSize;}
    
private:
    bool          _valid;
    bool          _hasScale;
    int32_t       _scaleX; // fixed point 32 bits 16.16
    int32_t       _scaleY; // fixed point 32 bits 16.16
    bool          _hasRotate;
    int32_t       _rotateSkew0; // fixed point 32 bits 16.16
    int32_t       _rotateSkew1; // fixed point 32 bits 16.16
    int32_t       _translateX;
    int32_t       _translateY;
    uint32_t      _dataSize;
};

class CXFormRecord
{
public:
    CXFormRecord() : _valid(false), 
                     _hasAddTerms(false), _redMultTerm(0), _greenMultTerm(0), _blueMultTerm(0),
                     _hasMultTerms(false), _redAddTerm(0), _greenAddTerm(0), _blueAddTerm(0),
                     _dataSize(0) {}
    
    void create(const char* source, uint32_t dataMax);
    
    bool valid() {return _valid;}
    bool hasAddTerms() {return _hasAddTerms;}
    int32_t  redMultTerm() {return _redMultTerm;}
    int32_t  greenMultTerm() {return _greenMultTerm;}
    int32_t  blueMultTerm() {return _blueMultTerm;}
    bool hasMultTerms() {return _hasMultTerms;}
    int32_t  redAddTerm() {return _redAddTerm;}
    int32_t  greenAddTerm() {return _greenAddTerm;}
    int32_t  blueAddTerm() {return _blueAddTerm;}
    uint32_t dataSize() {return _dataSize;}
    
private:
    bool          _valid;
    bool          _hasAddTerms;
    int32_t       _redMultTerm;
    int32_t       _greenMultTerm;
    int32_t       _blueMultTerm;
    bool          _hasMultTerms;
    int32_t       _redAddTerm;
    int32_t       _greenAddTerm;
    int32_t       _blueAddTerm;
    uint32_t      _dataSize;
};

class RGBRecord
{
public:
    RGBRecord() : _valid(false), _red(0), _green(0), _blue(0) {}
    
    void create(const char* source, uint32_t dataMax);
    
    bool    valid() {return _valid;}
    uint8_t red() {return _red;}
    uint8_t green() {return _green;}
    uint8_t blue() {return _blue;}
    
private:
    bool          _valid;
    uint8_t       _red;
    uint8_t       _green;
    uint8_t       _blue;
};

class RGBARecord
{
public:
    RGBARecord() : _valid(false), _red(0), _green(0), _blue(0), _alpha(0) {}
    
    void create(const char* source, uint32_t dataMax);
    
    bool    valid() {return _valid;}
    uint8_t red()   {return _red;}
    uint8_t green() {return _green;}
    uint8_t blue()  {return _blue;}
    uint8_t alpha() {return _alpha;}
    
private:
    bool          _valid;
    uint8_t       _red;
    uint8_t       _green;
    uint8_t       _blue;
    uint8_t       _alpha;
};

class ARGBRecord
{
public:
    ARGBRecord() : _valid(false), _red(0), _green(0), _blue(0), _alpha(0) {}
    
    void create(const char* source, uint32_t dataMax);
    
    bool    valid() {return _valid;}
    uint8_t red()   {return _red;}
    uint8_t green() {return _green;}
    uint8_t blue()  {return _blue;}
    uint8_t alpha() {return _alpha;}
    
private:
    bool          _valid;
    uint8_t       _red;
    uint8_t       _green;
    uint8_t       _blue;
    uint8_t       _alpha;
};

#endif // DATATYPES_H
