#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "UnionJack.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicApp : public App {
public:
    void setup() override;
    void draw() override;
    vector<UnionJack> mDisplays;
};

void BasicApp::setup()
{
    Color light = Color8u::hex( 0x42a1eb );
    Color dark = Color8u::hex( 0x082f4d );
	vec2 padding( 20 );

    mDisplays = {
        UnionJack( 11 ).display( "UnionJack *" ).scale( 3 ).position( padding )
            .colors(Color8u::hex( 0xf00000 ), Color8u::hex( 0x530000 )),
        // Let's print out the full ASCII table as a font specimen
        UnionJack( 33 ).display( " !\"#$%&'()*+,-./0123456789:;<=>?" ).colors( light, dark ),
        UnionJack( 33 ).display( "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_" ).colors( light, dark ),
       UnionJack( 33 ).display( "`abcdefghijklmnopqrstuvwxyz{|}~\x7F" ).colors( light, dark ),
    };
    // Position the displays relative to each other.
    mDisplays[1].below(mDisplays[0]);
    mDisplays[2].below(mDisplays[1]);
    mDisplays[3].below(mDisplays[2]);

    setWindowSize(padding + mDisplays[3].calcBoundingBox().getLowerRight());
}

void BasicApp::draw()
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
CINDER_APP( BasicApp, RendererGl( RendererGl::Options().msaa(16) ), prepareSettings )
