#include "cameras/perspective_camera.hpp"
#include "defines.hpp"
#include "renderer.hpp"

namespace RT_ISICG
{
	int main( int argc, char ** argv )
	{
		const int imgWidth	= 600;
		const int imgHeight = 400;

		// Create a texture to render the scene.
		Texture img = Texture( imgWidth, imgHeight );

		// Create and init scene.
		Scene scene;
		scene.init();

		// Create a perspective camera.
		//PerspectiveCamera camera( float( imgWidth ) / imgHeight );

		//TP1_Exo 4_2 :
		//PerspectiveCamera camera(Vec3f( 0.f, 0.f, -2.f ), Vec3f( 0.f, 0.f, 79.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float(imgWidth)/imgHeight);
		//PerspectiveCamera camera( Vec3f( 1.f, 0.f, 0.f ), Vec3f( 1.f, 0.f, 1.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float(imgWidth)/imgHeight); 
		//PerspectiveCamera camera( Vec3f( 0.f, 1.f, 0.f ), Vec3f( 0.f, 1.f, 1.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float(imgWidth)/imgHeight);
		//PerspectiveCamera camera( Vec3f( 4.f, -1.f, 0.f ), Vec3f( -1.f, -1.f, 2.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float(imgWidth)/imgHeight);

		// TP3 Recul de la camera 
		//PerspectiveCamera camera( Vec3f( 0.1f, 0.f, -2.f ), Vec3f( 0.f, 0.f, 1.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float( imgWidth ) / imgHeight );

		// TP5 Configuration de la scene
		//PerspectiveCamera camera( Vec3f( 0.f, 2.f, -6.f ), Vec3f( 0.f, 0.f, 1.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float( imgWidth ) / imgHeight );
		// Pour voir le plan vert situ? en hauteur
		PerspectiveCamera camera(Vec3f( 0.f, 2.f, -6.f ), Vec3f( 0.f, 0.f, 80.f ), Vec3f( 0.f, 1.f, 0.f ), 60.f, float( imgWidth ) / imgHeight );

		// Create and setup the renderer.
		Renderer renderer;
		renderer.setIntegrator( IntegratorType::WHITTED );
		renderer.setBackgroundColor( GREY );

		// TP3_Exo 2_5 :
		// Suppression Anti-aliasing
		//renderer.setNbPixelSamples( 1 );

		// TP1_Exo 5 :
		// Anti-aliasing
		renderer.setNbPixelSamples( 32 );

		// Launch rendering.
		std::cout << "Rendering..." << std::endl;
		std::cout << "- Image size: " << imgWidth << "x" << imgHeight << std::endl;

		float renderingTime = renderer.renderImage( scene, &camera, img );

		std::cout << "-> Done in " << renderingTime << "ms" << std::endl;

		// Save rendered image.
		const std::string imgName = "image.jpg";
		img.saveJPG( RESULTS_PATH + imgName );

		return EXIT_SUCCESS;
	}
} // namespace RT_ISICG

int main( int argc, char ** argv )
{
	try
	{
		return RT_ISICG::main( argc, argv );
	}
	catch ( const std::exception & e )
	{
		std::cerr << "Exception caught:" << std::endl << e.what() << std::endl;
	}
}
