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

using namespace ci;
using namespace std;

class UnionJack {
public:
    UnionJack( uint digits = 10, float slant = 0.2f );

    // Set the xy position.
    UnionJack& position( const vec2 &p );
    // Set the xy position to be below another display.
    UnionJack& below( const UnionJack &other );
    // Set the xy position to be right of another display.
    UnionJack& rightOf( const UnionJack &other );
    // Scale display. The default character size is 16 x 24.
    UnionJack& scale( const float &s );
    // Set the on and off colors.
    UnionJack& colors( const ColorA &on, const ColorA &off );
    // Set the text to display. Strings longer than the display size will be
    // truncated. Strings shorter than the display size will be padded with
    // spaces.
    UnionJack& display( string s );

    void draw() const;

    const vec2 position() const { return mPosition; }
    float height() const;
    float width() const;

    // Returns the pattern for a printable ASCII character (33-127) in our font.
    // Out of range values return blank.
    uint16_t valueOf( const char );

protected:
    void setup();
    mat4 modelMatrix() const;

    uint            mDigits; // Number of characters in display
    ci::vec2        mPosition;
    float           mScale;
    float           mSlant; // Positive leans right, negative leans left
    ci::vec4        mOnColor;
    ci::vec4        mOffColor;
    gl::BatchRef    mBatch;
    gl::VboRef      mInstancePositionVbo;
    gl::VboRef      mInstanceValueVbo;
};

#endif /* defined(__UnionJack__) */
