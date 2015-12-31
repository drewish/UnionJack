//
//  UnionJack.h
//
//  Draws 16-segments displays aka "Union Jack"
//
//  Created by Andrew Morton on 11/6/14.
//

#ifndef __UnionJack__
#define __UnionJack__

#include "cinder/gl/Vbo.h"

class UnionJack {
public:
    // Create a blank display with *length* character.
    UnionJack( uint length = 10 );
    // Create the display from a string. The length will be based on the string length.
    UnionJack( const std::string &display );

    // Set position

    // Set the xy position.
    UnionJack& position( const ci::vec2 &p );
    // Set the xy position to be left aligned below another display.
    UnionJack& below( const UnionJack &other );
    // Set the xy position to be bottom aligned, right of another display.
    UnionJack& rightOf( const UnionJack &other );

    // Set appearance

    // Applies a slant factor. Positive is to the right, negative to the left.
    UnionJack& slant( const float &s );
    // Scale display. The default character size is 16 x 24.
    UnionJack& scale( const float &s );
    // Set the on and off colors.
    UnionJack& colors( const ci::ColorA &on, const ci::ColorA &off );

    // Set displayed values

    // Set the text to display. Strings longer than the display size will be
    // truncated. Strings shorter than length() will be padded with spaces.
    UnionJack& display( const std::string &s );
    // Set the text to raw bit patterns. The vector's size must be less than or
    // equal length(). If the vector is shorter than the display's length, the
    // remaning characters will be cleared.
    UnionJack& display( const std::vector<uint16_t> &raw_values );
    // Set a single character to raw. The at parameter must be less than
    // length().
    UnionJack& display( const size_t at, const uint16_t raw_value );


    void draw() const;

    // Access dimensions

    size_t      length() const { return mBuffer.size(); }
    ci::vec2    position() const { return mPosition; }
    float       height() const;
    float       width() const;
    ci::Rectf   calcBoundingBox() const;

    // Returns the pattern for a printable ASCII character (33-127) in our font.
    // Out of range values return blank.
    uint16_t valueOf( const char ) const;

    // Character dimensions before scaling or slanting.
    static const uint CHARACTER_HEIGTH = 24;
    static const uint CHARACTER_WIDTH = 16;

protected:
    void        setup();
    void        updateVBO();
    ci::mat4    modelMatrix() const;

    std::vector<uint16_t>   mBuffer;
    ci::vec2                mPosition = ci::vec2();
    float                   mScale = 1.0f;
    float                   mSlant = 0.2f;
    ci::vec4                mOnColor;
    ci::vec4                mOffColor;
    ci::gl::BatchRef        mBatch;
    ci::gl::VboRef          mInstanceValueVbo;
};

#endif /* defined(__UnionJack__) */
