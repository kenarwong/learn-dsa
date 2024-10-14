#include "headers.h"
#include "Sport.h"
#include "Snowboarding.h"
#include "Biathlon.h"
#include "FigureSkating.h"

using namespace std;

//Your declarations and implementations would go here

void display(const Sport* sp)
{
    cout << sp->name() << " is ";
    if (sp->isOutdoor())
        cout << "an outdoor sport ";
    else
        cout << "an indoor sport ";
    cout << "with an icon showing " << sp->icon() << "." << endl;
}

int main()
{

  int n = 4;
  Sport *sports[n];
  sports[0] = new Snowboarding("Women's halfpipe");
  // Biathlon events have a distance in kilometers
  sports[1] = new Biathlon("Men's pursuit", 12.5);
  sports[2] = new Biathlon("Women's sprint", 7.5);
  sports[3] = new FigureSkating("Pair skating free");

  cout << "Here are the sports." << endl;
  for (int k = 0; k < n; k++)
      display(sports[k]);

  // Clean up the sports before exiting
  cout << "Cleaning up." << endl;
  for (int k = 0; k < n; k++)
    delete sports[k];

  /* Expected output
    Here are the sports.
    Women's halfpipe is an outdoor sport with an icon showing a descending snowboarder.
    Men's pursuit is an outdoor sport with an icon showing a skier with a rifle.
    Women's sprint is an outdoor sport with an icon showing a skier with a rifle.
    Pair skating free is an indoor sport with an icon showing a skater in the Biellmann position.
    Cleaning up.
    Destroying the Snowboarding object named Women's halfpipe.
    Destroying the Biathlon object named Men's pursuit, distance 12.5 km.
    Destroying the Biathlon object named Women's sprint, distance 7.5 km.
    Destroying the FigureSkating object named Pair skating free.
  */

  return 0;
} 