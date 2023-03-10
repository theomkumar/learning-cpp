/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution {
public:

    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        //Your code here
        int totalPetrol = 0, currentPetrol = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            currentPetrol += p[i].petrol - p[i].distance;
            if (currentPetrol < 0)
            {
                totalPetrol += currentPetrol;
                currentPetrol = 0;
                start = i + 1;
            }
        }
        totalPetrol += currentPetrol;
        if (totalPetrol < 0)
            return -1;
        return start;
    }
};
