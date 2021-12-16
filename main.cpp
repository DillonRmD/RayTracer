
#define DTB_MATH_USE_TYPES
#include "dtb_math.h"

#include <iostream>
#include <fstream>

#define ASPECT_RATIO (int)(16.0 / 9.0)
#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT IMAGE_WIDTH / ASPECT_RATIO

struct Ray {
    v3 origin;
    v3 direction;
};

v3 PositionAtTime(Ray r, double t){
    return r.origin + t * r.direction;
}

bool IsHitSphere(v3 center, double radius, Ray r) {
    v3 oc = r.origin - center;
    double a = dtbVec3_Dot(r.direction, r.direction);
    double b = 2.0 * dtbVec3_Dot(oc, r.direction);
    double c = dtbVec3_Dot(oc, oc) - radius*radius;
    double discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

v3 CaclulateRayColor(Ray r) {
    if (IsHitSphere(dtbVec3(0,0,-1), 0.5, r))
        return dtbVec3(0, 1, 0);
    v3 unit_direction = dtbVec3_Normalize(r.direction);
    double t = 0.5*(unit_direction.y + 1.0);
    return (1.0-t)*dtbVec3(1.0, 1.0, 1.0) + t*dtbVec3(0.5, 0.7, 1.0);
}

void WriteColorToFile(std::ostream &out, v3 pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';
}

int main() {

    // Camera

    double viewport_height = 2.0;
    double viewport_width = ASPECT_RATIO * viewport_height;
    double focal_length = 1.0;

    v3 origin = dtbVec3(0, 0, 0);
    v3 horizontal = dtbVec3(viewport_width, 0, 0);
    v3 vertical = dtbVec3(0, viewport_height, 0);
    v3 lowerLeftCorner = origin - horizontal/2 - vertical/2 - dtbVec3(0, 0, focal_length);

    // Render
    std::ofstream imageFile;
    imageFile.open("image.ppm");

    imageFile << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";
    for (int j = IMAGE_HEIGHT-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            double u = double(i) / (IMAGE_WIDTH-1);
            double v = double(j) / (IMAGE_HEIGHT-1);
            
            Ray r = {0};
            r.origin = origin;
            r.direction = lowerLeftCorner + (u * horizontal) + (v * vertical) - origin;

            v3 pixel_color = CaclulateRayColor(r);
            WriteColorToFile(imageFile, pixel_color);
        }
    }
    imageFile.close();
    std::cerr << "\nDone.\n";
}