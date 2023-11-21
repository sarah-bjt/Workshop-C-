#include <sil/sil.hpp>
#include <cmath>
#include "random.hpp"

void onlyGreen (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
    color.r = 0.f;
    color.b = 0.f;
    }
    image.save("output/ex01onlyGreen.png");
}


void blueAndRedReverse (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        float a {color.r};
        color.r = color.b;
        color.b = a;
    }
    image.save("output/ex02blueAndRedReverse.png");    
}

void blackAndWhite (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        float moy {(color.r+color.b+color.g)/3};
        color.g = moy;
        color.r = moy;
        color.b = moy;
    }
    image.save("output/ex03blackAndWhite.png");
}

void inverteColor (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        color.g = 1 - color.g;
        color.b = 1 - color.b;
        color.r = 1 - color.r;
    }
    image.save("output/ex04inverteColor.png");    
}

void degrader ()
{
    sil::Image image{300/*width*/, 200/*height*/};
    for (float x{0}; x < image.width(); x++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            float couleur  = x/300;
            image.pixel(x,y).r = couleur;
            image.pixel(x,y).b = couleur;
            image.pixel(x,y).g = couleur;   
        }
    }
    image.save("output/ex05degrader.png");    
}

void miroir (sil::Image image)
{
    sil::Image copyImage {image.width(), image.height()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            copyImage.pixel(x, y).r = image.pixel(image.width()-1-x, y).r;
            copyImage.pixel(x, y).b = image.pixel(image.width()-1-x, y).b;
            copyImage.pixel(x, y).g = image.pixel(image.width()-1-x, y).g;
        }
    }
    copyImage.save("output/ex06miroir.png");   
}

void imageBruit (sil::Image image)
{
    for (glm::vec3& color : image.pixels())
    {
        int isPixelBruit {random_int(0, 4)};
        if (isPixelBruit == 1)
        {
            color.r =  random_float(0, 1);
            color.b =  random_float(0, 1);
            color.g =  random_float(0, 1);
        }
    }
    image.save("output/ex07imageBruit.png");    
}

void rotation90 (sil::Image image, sil::Image result) // attention ne fonctionne pas 
{
    for (int x{0}; x < result.width(); x++)
    {
        for (int y{0}; y < result.height(); y++)
        {
            result.pixel(x, y) = image.pixel(image.height()-x, image.width()-y);
        }
    }
    result.save("output/ex08rotation90.png");
}

// void RGBsplit (sil::Image image) // effet arlequin
// {
//     sil::Image copy {image};
//     for (int x{0}; x < image.width()-(image.width()/5); x++) // pour le rouge vers la drt
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//             copy.pixel(x+(image.width()/5), y).r = image.pixel(x,y).r;
//         }
//     }
//     for (int x{(image.width()/5)}; x< image.width(); x++) // pour le bleu vers la gch
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//             copy.pixel(x - (image.width()/5), y).b = image.pixel(x,y).b;
//         }
//     }
//     copy.save("output/ex09RGBsplit.png");
// }

void RGBsplit (sil::Image image)
{
    sil::Image copy {image.width(),image.height()};
    for (int x{0}; x < image.width()-(image.width()/9); x++) // pour le rouge vers la drt
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x+(image.width()/9), y).r = image.pixel(x,y).r;
        }
    }
    for (int x{(image.width()/9)}; x< image.width(); x++) // pour le bleu vers la gch
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x - (image.width()/9), y).b = image.pixel(x,y).b;
        }
    }
    for (int x{}; x< image.width(); x++) // pour le vert
    {
        for (int y{0}; y < image.height(); y++)
        {
            copy.pixel(x , y).g = image.pixel(x,y).g;
        }
    }
    copy.save("output/ex09RGBsplit.png");
}

void luminosite (sil::Image image)
{

    for (glm::vec3& color : image.pixels())
    {
        {
            color.g = pow(color.g, 0.6);
            color.r = pow(color.r, 0.6);
            color.b = pow(color.b, 0.6);
        }
    }
    image.save("output/ex10luminosite.png");
}

void disque ()
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if( pow((x-250),2)+pow((y-250),2)< pow(200,2) )
            {
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
        }
    }
    image.save("output/ex11disque.png");
}


void cercle (int thickness)
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (pow((x-250),2)+pow((y-250),2)< pow(200,2) && pow((x-250),2)+pow((y-250),2)> pow(200-thickness,2) )
            {
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
        }
    }
    image.save("output/ex12cercle.png");
}

void rosace()
{
    sil::Image image{500/*width*/, 500/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (pow((x-250),2)+pow((y-250),2)< pow(100,2) && pow((x-250),2)+pow((y-250),2)> pow(100-10,2) )
            { //cercle centre
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
            else if (pow((x-250+95),2)+pow((y-250),2)< pow(100,2) && pow((x-250+95),2)+pow((y-250),2)> pow(100-10,2))
            { //cercle gch
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
            else if (pow((x-250-95),2)+pow((y-250),2)< pow(100,2) && pow((x-250-95),2)+pow((y-250),2)> pow(100-10,2))
            { //cercle drt
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }
            else if (pow((x-250-95),2)+pow((y-250),2)< pow(100,2) && pow((x-250-95),2)+pow((y-250),2)> pow(100-10,2))
            { //cercle haut gch
                image.pixel(x,y).g = 1;
                image.pixel(x,y).r = 1;
                image.pixel(x,y).b = 1;
            }

        }
    }
    image.save("output/ex13rosace.png");
}
int main()
{
    set_random_seed(0);
    sil::Image logo{"images/logo.png"};
    sil::Image photo{"images/photo_faible_contraste.jpg"};
    sil::Image photoc{"images/photo.jpg"};
    sil::Image result {345, 300};
//    onlyGreen(logo);
//    blueAndRedReverse(logo);
//    blackAndWhite(logo);
//    inverteColor(logo);
//    degrader();
//    miroir(logo);
//    imageBruit(logo);
//    rotation90(logo,result); //attention ne fonctionne pas
//    RGBsplit(logo);
//    luminosite(photoc);
//    disque();
//    cercle(50);
    rosace();
    return 0;
}