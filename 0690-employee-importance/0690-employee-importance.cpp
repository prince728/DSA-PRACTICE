/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(unordered_map<int, Employee*> employeeMap, int id) {
        int sum=employeeMap[id]->importance;

        for(int i=0;i<employeeMap[id]->subordinates.size();i++){
           sum+= dfs(employeeMap,employeeMap[id]->subordinates[i]);
        }


        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        unordered_map<int, Employee*> employeeMap;

        for (int i = 0; i < employees.size(); i++) {
            employeeMap[employees[i]->id] = employees[i];
        }

        return dfs(employeeMap, id);
    }
};