# UnionJack
CinderBlock for emulating a 16-segment LED display using OpenGL.

![Screenshot](PREVIEW.png)

## Installation

Download or check out this repoistory into your `Cinder/blocks` directory, then
use [Tinderbox](https://libcinder.org/docs/guides/tinderbox/) to create a new
project using UnionJack.

## Example

```c++
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "UnionJack.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectApp : public App {
public:
    void setup() override;
    void draw() override;

    vector<UnionJack> mDisplays;
};

void CinderProjectApp::setup()
{
    Color light = Color8u::hex( 0x42a1eb );
    Color dark = Color8u::hex( 0x082f4d );
    vec2 padding( 20 );

    mDisplays = {
        UnionJack( 11 ).display( "UnionJack *" ).scale( 3 ).position( padding )
            .colors( Color8u::hex( 0xf00000 ), Color8u::hex( 0x530000 ) ),
        // Let's print out the full ASCII table as a font specimen
        UnionJack( 33 ).display( " !\"#$%&'()*+,-./0123456789:;<=>?"   ).colors( light, dark ),
        UnionJack( 33 ).display( "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"   ).colors( light, dark ),
        UnionJack( 33 ).display( "`abcdefghijklmnopqrstuvwxyz{|}~\x7F" ).colors( light, dark ),
    };
    // Position the displays relative to each other.
    mDisplays[1].below( mDisplays[0] );
    mDisplays[2].below( mDisplays[1] );
    mDisplays[3].below( mDisplays[2] );

    setWindowSize( padding + mDisplays[3].calcBoundingBox().getLowerRight() );
}

void CinderProjectApp::draw()
{
    gl::clear( Color::black() );
    for ( auto display = mDisplays.begin(); display != mDisplays.end(); ++display ) {
        display->draw();
    }
}

void prepareSettings( App::Settings *settings )
{
    settings->setHighDensityDisplayEnabled();
}

CINDER_APP( CinderProjectApp, RendererGl( RendererGl::Options().msaa( 16 ) ), prepareSettings )
```

## Credit
- The font is from Matthew Sarnoff's [32-character serial LED display](http://www.msarnoff.org/alpha32/) project.
