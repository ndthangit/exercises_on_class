#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
using namespace std;

typedef struct verticesList
{
    vector<string> vertex;
} verticesList;

bool check2differentWords(const string &word1, const string &word2)
{
    if (word1.length() != word2.length())
        return false;

    int different = 0;
    for (int i = 0; i < word1.length(); i++)
    {
        if (word1[i] != word2[i])
        {
            different++;
        }
    }
    if (different == 1)
    {
        return true;
    }
    else
        return false;
}
void setupTree(map<string, verticesList> &edgeList, map<string, bool> &visitedEdgeList)
{
    for (auto &word1 : visitedEdgeList)
    {
        for (auto &word2 : visitedEdgeList)
        {
            if (check2differentWords(word1.first, word2.first))
            {
                edgeList[word1.first].vertex.push_back(word2.first);
            }
        }
    }
}
void explore(map<string, verticesList> &edgeList, map<string, bool> &visitedEdgeList, const string currentVertex)
{
    visitedEdgeList[currentVertex] = true;
    for (int i = 0; i < edgeList[currentVertex].vertex.size(); i++)
    {
        if (visitedEdgeList[edgeList[currentVertex].vertex[i]] == false)
        {
            explore(edgeList, visitedEdgeList, edgeList[currentVertex].vertex[i]);
        }
    }
}
int findTheNumberOfInternalLink(map<string, verticesList> &edgeList, map<string, bool> &visitedEdgeList)
{
    // dfs algorithm find the number of internal link
    int coutTheNUmberOfInternalLink = 0;
    for (auto &word : visitedEdgeList)
    {
        coutTheNUmberOfInternalLink++;
        if (visitedEdgeList[word.first] == false)
        {
            coutTheNUmberOfInternalLink++;
            explore(edgeList, visitedEdgeList, word.first);
        }
    }
    for (auto &word : visitedEdgeList)
    {
        visitedEdgeList[word.first] = false;
    }
    return coutTheNUmberOfInternalLink;
}
void findTheMinimumPath(map<string, verticesList> &edgeList, map<string, bool> &visitedEdgeList)
{

    for (auto &word : visitedEdgeList)
    {
        visitedEdgeList[word.first] = false;
    }
}
int main()
{
    map<string, bool> visitedEdgeList;
    map<string, verticesList> edgeList;

    ifstream inputFile("sgb-words.txt");

    string word;
    while (inputFile >> word)
    {
        visitedEdgeList.insert({word, false});
    }
    inputFile.close();

    setupTree(edgeList, visitedEdgeList);

    cout << "the number of internal link in graph: " << findTheNumberOfInternalLink(edgeList, visitedEdgeList) << endl;
    cout << visitedEdgeList["spumy"];
    // ok
    // string which = "which";
    // for (int i = 0; i < edgeList[which].vertex.size(); i++)
    // {
    //     cout << edgeList[which].vertex[i] << endl;
    // }

    return 0;
}