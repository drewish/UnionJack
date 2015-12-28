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
    UnionJack( uint digits );

    // Chain-able configuration methods
    UnionJack& position( const vec2 &p );
    UnionJack& below( const UnionJack &other );
    UnionJack& rightOf( const UnionJack &other );
    UnionJack& scale( const float &s );
    UnionJack& colors( const ColorA &on, const ColorA &off );
    UnionJack& display( string s );

    void setup();
    void draw() const;

    const vec2 position() const { return mPosition; }
    float height() const;
    float width() const;

    // Returns the pattern for a printable ASCII character in our font.
    // Out of range values return blank.
    uint16_t valueOf( const char );

protected:
    uint            mDigits; // Number of characters in display
    ci::vec2        mPosition;
    float           mScale;
    float           mSlant; // Positive leans right, negative leans left
    ci::vec4        mColors[2]; // 0 is off 1 is on
    gl::BatchRef    mBatch;

    gl::VboRef      mInstancePositionVbo;
    gl::VboRef      mInstanceValueVbo;
};

#endif /* defined(__UnionJack__) */
