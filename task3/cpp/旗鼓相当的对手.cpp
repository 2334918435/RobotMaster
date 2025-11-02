#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Student {
    int chinese;
    int math;
    int english;
    int total;
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        int c, m, e;
        cin >> c >> m >> e;
        Student s;  
        s.chinese = c;
        s.math = m;
        s.english = e;
        s.total = c + m + e;
        students.push_back(s);
    }
    
    int count = 0;
   
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
     
            if (abs(students[i].chinese - students[j].chinese) > 5)
                continue;
            if (abs(students[i].math - students[j].math) > 5)
                continue;
            if (abs(students[i].english - students[j].english) > 5)
                continue;

            if (abs(students[i].total - students[j].total) > 10)
                continue;
     
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}