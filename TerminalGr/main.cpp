#include <iostream>
#include <cmath>


int main(int argc, const char * argv[]) {
    int width = 120;
    int height = 30;
    int depth = 30;
    float aspect = (float)width / height;
    float pixelAspect = 14.0f / 28.0f;
    char gradient[] = " .':,\"!/r(l1Z4H9W8$@";
    int gradientSize = std::size(gradient) - 2;
    char *screen = new char[width * height +1];
    screen[width * height] = '\0';
    for(int t = 0; t < 4000; t++)
    {
        for(int u = 0; u < depth; u++)
        {
            for(int i = 0; i < width; i++)
            {
                for(int j = 0; j < height; j++)
                {
                    float z = (float)u / depth * 2.0f - 1.0f;
                    z *= aspect * pixelAspect;
                    z += sin(t * 0.001);
                    float x = (float)i / width * z * 2.0f - 1.0f;
                    float y = (float)j / height * z * 2.0f - 1.0f;
                    x *= aspect * pixelAspect;
                    x += sin(t * 0.0001);
                    y += sin(t * -0.0001);
                    char pixel = ' ';
                    float dist = sqrt(x * x + y * y);
                    int color = (int)(1.0f / dist);
                    if(color < 0) color = 0;
                    else if(color > gradientSize) color = gradientSize;
                    pixel = gradient[color];
                    screen[i + j * width] = pixel;
                }
            }
        }

        std::cout << screen << std::endl;
    }

    getchar();
    return 0;
}
