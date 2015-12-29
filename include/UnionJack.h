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
    UnionJack( uint length = 10 );

    // Set the xy position.
    UnionJack& position( const ci::vec2 &p );
    // Set the xy position to be below another display.
    UnionJack& below( const UnionJack &other );
    // Set the xy position to be right of another display.
    UnionJack& rightOf( const UnionJack &other );

    // Applies a slant factor. Positive is to the right, negative to the left.
    UnionJack& slant( const float &s );
    // Scale display. The default character size is 16 x 24.
    UnionJack& scale( const float &s );
    // Set the on and off colors.
    UnionJack& colors( const ci::ColorA &on, const ci::ColorA &off );
    // Set the text to display. Strings longer than the display size will be
    // truncated. Strings shorter than the display size will be padded with
    // spaces.
    UnionJack& display( std::string s );

    void draw() const;

    ci::vec2    position() const { return mPosition; }
    float       height() const;
    float       width() const;
    ci::Rectf   calcBoundingBox() const;

    // Returns the pattern for a printable ASCII character (33-127) in our font.
    // Out of range values return blank.
    uint16_t valueOf( const char );

protected:
    void        setup();
    ci::mat4    modelMatrix() const;

    uint            mLength; // Number of characters in display
    ci::vec2        mPosition = ci::vec2();
    float           mScale = 1.0f;
    float           mSlant = 0.2f;
    ci::vec4        mOnColor;
    ci::vec4        mOffColor;
    ci::gl::BatchRef    mBatch;
    ci::gl::VboRef      mInstancePositionVbo;
    ci::gl::VboRef      mInstanceValueVbo;
};

#endif /* defined(__UnionJack__) */
