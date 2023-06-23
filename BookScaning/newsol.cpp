#include <iostream>
#include <string>
#include <list>
#include <fstream>
#define IO System::IO
using namespace std;



class TrafficLights 
{
    public:
        int durationinSec;
        int NumOfIntersection;
        int NumOfStreets;
        int NumOfCars;
        int BonusPointsBeforeTime;

        list<Street> streets;
        list<CarPath> carPaths;

};

class Street
{
    public:
        int IntersectionStartStreet;
        int IntersectionEndStreet;
        string StreetName;
        int TimeStartEndStreet;

};

class CarPath
{
    int NumOfStreet;
    list<string> StreetName;
};

TrafficLights ReadInputFile(string fileName)
{
    //http://www.cplusplus.com/forum/beginner/74757/
    var lines = readAllLines(fileName);

    var line = lines[0];
    var fline = line.Split(' ');
    TrafficLights trafficLight = new TrafficLights(); //create a traffic light object  - 1. LibraryData class 2. global variable (Program)

    trafficLight.durationinSec = int.Parse(fline[0]);
    trafficLight.NumOfIntersection = int.Parse(fline[1]);
    trafficLight.NumOfStreets = int.Parse(fline[2]);
    trafficLight.NumOfCars = int.Parse(fline[3]);
    trafficLight.BonusPointsBeforeTime = int.Parse(fline[4]);


    for (var i = 1; i < trafficLight.NumOfStreets + 1; i++)
    {
        var otherLines = lines[i].Split(' ');
        Street street = new Street();
        street.IntersectionStartStreet = int.Parse(otherLines[0]);
        street.IntersectionEndStreet = int.Parse(otherLines[1]);
        street.StreetName = otherLines[2];
        street.TimeStartEndStreet = int.Parse(otherLines[3]);
        trafficLight.streets.Add(street);
    }

    for (var i = trafficLight.streets.Count + 1; i < trafficLight.streets.Count + trafficLight.NumOfCars + 1; i++)
    {
        var otherLines = lines[i].Split(' ');
        CarPath carPath = new CarPath();
        carPath.NumOfStreet = int.Parse(otherLines[0]);
        carPath.StreetName = otherLines.Skip(1).ToList();
        trafficLight.carPaths.Add(carPath);
    }
    trafficLight.carPaths = trafficLight.carPaths.OrderBy(p => p.NumOfStreet).ToList();
    return trafficLight;
}


int main() {

    string path = "";
    string fileName = "a.txt";
    
    try
    {
        TrafficLights TrafficLights = ReadInputFile(path + fileName);
        OutPutFile outPutFile = new OutPutFile();
        outPutFile = ScheduleIntersection(TrafficLights);
        WriteOutputFile(outPutFile);
    }
    catch (Exception exc) { Console.WriteLine(exc.Message); }
}

