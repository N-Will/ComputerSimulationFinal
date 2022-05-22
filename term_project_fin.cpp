// Nick Williams
// CPSC 320 Assignment #5 / Term Project
// This program simulates traffic and finds out which direction is more efficient to go in at this intersection

// Include statements below
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <queue>
#include <ctime>
using namespace std;

// Generate a random number between 1 and 100
int generate()
{
	int x = rand() % 100;
	return x;
}

// Main function to run the program
int main()
{
	// Seed random number generator
    srand(time(NULL));
	
	// Odds of cars arriving from the North / South
	const double NS_frequency = generate();
	
	// Odds of cars arriving from the West / East
	const double WE_frequency = generate();
	
	// Runtime of the simulation (one hour in seconds)
	const double runtime = 3600.0;
    
    // Declare queue variables
    queue<int> north_or_south;
    queue<int> west_or_east;
	
	// Declare basic integer variables
    int time;
    int minute = 60; 
    int seconds_NS = 0;
    int mins_NS = 0;
    int seconds_WE = 0;
    int mins_WE = 0;
    
    // Make these ones doubles so we can avoid integer division later
    double counter_NS = 0.0;
    double counter_WE = 0.0;
    double hold = 0.0;
    
    // Simulate the traffic
    for (time = 1; time <= runtime; time++)
    {
    	// An arrival has happened
        if (generate() <= NS_frequency)
        {
            north_or_south.push(time);
            counter_NS++;
        }
        // A departure (arrival from other road) has happened
        if (generate() <= WE_frequency)
        {
            west_or_east.push(time);
            counter_WE++;
        }        
    }
    
    // GATHER AND PRINT INFORMATION BELOW //
    
    // Print the predicted frequencies
    cout << "The North / South road's predicted frequency was at " << NS_frequency << "% of its maximum capacity." << endl;
    cout << "The West / East road's predicted frequency was at " << WE_frequency << "% of its maximum capacity." << endl;
    cout << endl;
    
    // Print the actual calculated frequencies of each road
    cout << "The North / South road's actual frequency was at " << (counter_NS / runtime) * 100 << "% of its maximum capacity." << endl;
    cout << "The West / East road's actual frequency was at " << (counter_WE / runtime) * 100 << "% of its maximum capacity." << endl;
    cout << endl;
    
    // Print the queue sizes of each road
    cout << "There were " << north_or_south.size() << " cars on the North / South road at the intersection." << endl;
    cout << "There were " << west_or_east.size() << " cars on the West / East road at the intersection." << endl;
    cout << endl;
    
    // If / else based on which road is more busy, print calculated information below
    if(north_or_south.size() >= west_or_east.size())
    {
    	hold = counter_NS / counter_WE;
    	cout << "The North / South road was " << hold << " times as busy as the West / East road." << endl;
	}
	else if(west_or_east.size() >= north_or_south.size())
	{
		hold = counter_WE / counter_NS;
		cout << "The West / East road was " << hold << " times as busy as the North / South road." << endl;
	}
	
	// Just here for nicer spacing
	cout << endl;
	
	// For some reason the time is incremented an extra one
	time = time - 1; 

	// Calculate and print the total time the North / South road was in use
    seconds_NS = north_or_south.size() % minute;
	mins_NS = north_or_south.size() - seconds_NS;
	mins_NS = mins_NS / 60;
    cout << "The North / South road was in use for " << mins_NS << " minutes and " << seconds_NS << " seconds." << endl;
    
    // Calculate and print the total time the East / West road was in use
    seconds_WE = west_or_east.size() % minute;
    mins_WE = west_or_east.size() - seconds_WE;
    mins_WE = mins_WE / 60;
    cout << "The West / East road was in use for " << mins_WE << " minutes and " << seconds_WE << " seconds." << endl;
}



