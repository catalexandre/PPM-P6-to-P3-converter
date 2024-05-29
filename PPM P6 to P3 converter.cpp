
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string inputFile;

    cout << "name of the input file (exclude file extension): ";
    cin >> inputFile;

    ifstream image(inputFile + ".ppm", ios::binary);

    if (!image.is_open())
    {
        cout << "Encountered a problem when opening the file";
        return 1;
    }
        
    ofstream newImage(inputFile + "P3.ppm");

    newImage << "P3" << endl;

    int width, height, maxValue;
    image.ignore(256, '\n');
    image >> width >> height;
    image.ignore(256, '\n');
    image >> maxValue;
    newImage << width << ' ' << height << endl << maxValue << endl;

    image.ignore(256, '\n');

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char r, g, b;
            image.read(reinterpret_cast<char*>(&r), 1);
            image.read(reinterpret_cast<char*>(&g), 1);
            image.read(reinterpret_cast<char*>(&b), 1);
            newImage << static_cast<int>(r) << " " << static_cast<int>(g) << " " << static_cast<int>(b) << " ";
        }
    }

    image.close();
    newImage.close();
}