
#include <memory>
#include <queue>
#include <iostream>
#include <vector>
#include <memory>

#include <algorithm>

#include <unordered_set>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

struct Node
{

    std::vector<int> value;
    int level;
};
void printIntegerArr(vector<int> arr)
{
    // cout << "[";

    // for (int n : arr)
    //     cout << " " << n << " ";

    // cout << "]" << std::endl;
}

void PerumReverse(std::vector<int> &arr, std::vector<std::vector<int>> &out)
{

    for (auto windowSize = 1; windowSize <= arr.size(); windowSize++)
    {

        for (int i = 0; i <= arr.size() - windowSize; i++)
        {

            auto tmp = arr;

            std::vector<int>::iterator first = tmp.begin() + i;
            std::vector<int>::iterator last = first + windowSize;

            std::reverse(first, last);

            out.push_back(tmp);
        }
    }
}
struct hashFunction
{
    size_t operator()(const vector<int>
                          &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

int minOperations(vector<int> arr)
{
    // Write your code here

    std::vector<int> goal = arr;

    std::sort(goal.begin(), goal.end());

    std::unordered_set<vector<int>, hashFunction> visited;

    std::queue<Node> que;

    Node first;
    first.value = arr;
    first.level = 0;
    que.push(first);

    while (!que.empty())
    {

        Node tmp = que.front();
        que.pop();

        if (visited.find(tmp.value) != visited.end())
            continue;

        printIntegerArr(tmp.value);
        if (tmp.value == goal)
            return tmp.level;

        visited.insert(tmp.value);

        std::vector<std::vector<int>> out;

        PerumReverse(tmp.value, out);

        for (auto elem : out)
        {

            Node tmp_node;
            tmp_node.value = elem;
            tmp_node.level = tmp.level + 1;
            que.push(tmp_node);
        }
    }

    return 0;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n)
{
    cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output)
{
    bool result = (expected == output);
    const char *rightTick = u8"\u2713";
    const char *wrongTick = u8"\u2717";
    if (result)
    {
        cout << rightTick << "Test #" << test_case_number << "\n";
    }
    else
    {
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printInteger(expected);
        cout << " Your output: ";
        printInteger(output);
        cout << endl;
    }
    test_case_number++;
}

int main()
{

    int n_1 = 5;
    vector<int> arr_1{1, 2, 5, 4, 3};
    int expected_1 = 1;
    int output_1 = minOperations(arr_1);
    check(expected_1, output_1);

    int n_2 = 3;
    vector<int> arr_2{3, 1, 2};
    int expected_2 = 2;
    int output_2 = minOperations(arr_2);
    check(expected_2, output_2);

    // Add your own test cases here
}