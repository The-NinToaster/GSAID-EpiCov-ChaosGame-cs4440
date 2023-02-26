
#include <cmath>
#include <matplot/matplot.h>
#include "process.h"


using namespace std;

int* flatten(int** arr)
{
    int width = pow(2,7);
    int size = width * width; 
    int* flat = new int[size];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            flat[i * width + j] = arr[i][j];
        }
    }
    

    /**
    for(int k = 0; k < size; k++)
    {
        cout<<flat[k]<< " , ";
    }
    cout<<"\n";
    */
    
    return flat;
}

double compare_cgr(int** cgr1, int** cgr2)
{
    //This is using the euclidian distance of a vector
    int* flat_cgr1 = flatten(cgr1);
    int* flat_cgr2 = flatten(cgr2);
    int width = pow(2, 7);
    int size = width * width;
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += pow((flat_cgr1[i] - flat_cgr2[i]), 2);
    }

    double distance = sqrt(sum);
    return distance;
}

void process_distance(const std::vector<int**> *cgr_vector, std::vector<std::vector<double>> *distance_vector)
{
    //for every entry
    for(int i = 0; i < cgr_vector->size(); i++)
    {
        distance_vector->push_back(*new std::vector<double>);
        //comapre against every other entry, including itself
        for (int j = 0; j < cgr_vector->size(); j++)
        {
            distance_vector->at(i).push_back(compare_cgr(cgr_vector->at(i), cgr_vector->at(j)));
            //cout<< distance_vector->at(i).at(j) << " , ";

        }

        //cout << "\n";
    }
}


int main()
{
    process("Omicron");
    process("Delta");

    cout << "Performing cgr...." << "\n";
    std::vector<int**> *omicron_cgr = new std::vector<int**>;
    std::vector<int**> *delta_cgr = new std::vector<int**>;
    std::vector<std::vector<double>> *omicron_distance = new std::vector<std::vector<double>>;
    std::vector<std::vector<double>> *delta_distance = new std::vector<std::vector<double>>;
    cout<< "Omicron...\n";
    process_cgr("Omicron", omicron_cgr);
    cout<< "Delta....\n";
    process_cgr("Delta", delta_cgr);
    cout<< "Performing Euclidian Distance...\n";
    cout<< "Omicron...\n";
    process_distance(omicron_cgr, omicron_distance);
    cout<<"Delta...\n";
    process_distance(delta_cgr, delta_distance);
    
    /**
    * TODO: 
    * 1. Find a good MDS function or header
    * 2. Plot it into matplotplusplus
    */

    
    //free up that memory!
    delete omicron_cgr;
    delete omicron_distance;
    delete delta_cgr;
    delete delta_distance;
}

