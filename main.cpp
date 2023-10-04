/**********************************************
 * Author:       Platonov A.A.                *
 * Group:        ПИ-231                       *
 * Variant:      14                           *
 * Date:         27.09.2023                   *
 * Project name: Huge Filthy Pile of Printers *
 * OnlineGDB: https://onlinegdb.com/cLdMy3kBz *
 **********************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string fname, typeToShow, brandCheap, brandExpensive, numberCheap, numberExpensive;
  int costMin, costMax = -1, printersCount = 0;
  double costAverage = 0;
  
  cout << "Enter file name: ";
  cin >> fname; // Enter input.txt if you checking it on OnlineGDB
  
  ifstream fin(fname);
  
  if (!fin) {
    cout << "\nACHTUNG! Couldn't read the file '" + fname + "'!";
    return 1;
  }
  
  cout << "Enter type of printers to show (Laser or DotMatrix): ";
  cin >> typeToShow;
  
  while (!fin.eof()) {
    string brand, type, number;
    int cost;
    
    fin >> brand >> type >> number >> cost;
    
    if (type == typeToShow) {
      if (printersCount == 0) costMin = cost;
      
      printersCount++;
      costAverage += cost;
      
      cout << brand << ' ' << number << ", cost: " << cost << '\n';
      
      if (cost > costMax) {
        costMax = cost;
        numberExpensive = number;
        brandExpensive = brand;
      }
      
      if (cost < costMin) {
        costMin = cost;
        numberCheap = number;
        brandCheap = brand;
      }
    }
  }
  
  fin.close();
  
  costAverage /= printersCount;
  
  cout << "\nAverage cost of " << typeToShow << " printers: " << costAverage
       << "\nThe most cheap printer: " << brandCheap << ' ' << numberCheap
       << "\nThe most expensive printer: " << brandExpensive << ' ' << numberExpensive;
  
  return 0;
}
