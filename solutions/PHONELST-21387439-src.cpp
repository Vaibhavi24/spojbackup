#include<bits/stdc++.h>

using namespace std;

struct node
{
    struct node *parent;
    struct node *children[26];
    int count[26]={0};
    vector<int> occurrences;
};

bool insertWord(struct node *trieTree, char *word, int index)
{
       struct node *traverse = trieTree;

    while(*word != '\0')
    {
       if(traverse->occurrences.size()!=0)
       return 0;

        traverse->count[*word -'0']++;
        if(traverse->children[*word -'0'] == NULL)
        {
            traverse->children[*word -'0']=(struct node*)calloc(1, sizeof(struct node));
            traverse->children[*word -'0']->parent = traverse;
        }

        traverse = traverse->children[*word -'0'];
        word++;
    }

    for(int i=0;i<10;i++)
    if(traverse->children[i]!=NULL)
        return 0;

   traverse->occurrences.push_back(index);
   return 1;
}

struct node *searchWord(struct node *treeNode, char *word)
{
    while(*word != '\0')
    {
        char ch= *word;
        if(treeNode->children[ch-'a'] != NULL)
        {
            treeNode = treeNode->children[ch-'a'];
            ++word;
        }
        else break;
    }

    if(*word == '\0' && treeNode->occurrences.size()!=0)
        return treeNode;
    else return NULL;
}

void removeWord(struct node *trieTree, char *word)
{
    struct node *trieNode = searchWord(trieTree, word);

    if(trieNode == NULL)
        return;

    trieNode->occurrences.pop_back();

    bool noChild = true;

    int childCount=0;

    int i;

    for(i=0;i<26;i++)
    {
        if(trieNode->children[i] != NULL)
        {
            noChild = false;
            childCount++;
        }
    }

    if(!noChild)
        return;

    struct node *parentNode;
    while(trieNode->occurrences.size() == 0 && childCount == 0 && trieNode->parent != NULL)
    {
        childCount=0;
        parentNode = trieNode->parent;

        for(int i=0;i<26;i++)
        {
            if(parentNode->children[i]!=NULL)
            {
                if(parentNode->children[i] == trieNode)
            {
                parentNode->children[i] = NULL;
                free(trieNode);
                trieNode = parentNode;
            }
            else childCount++;
            }
        }
    }
}

void lexicographicalPrint(struct node *trieTree, vector<char> word)
{
    int i;
    bool noChild = true;

    if(trieTree->occurrences.size()!=0)
    {
        for(int i=0;i<word.size();i++)
            cout<<word[i];

        cout<<"Occurrences at :";
        for(int i=0;i< trieTree->occurrences.size();i++)
        {
            cout<<trieTree->occurrences[i]<<" ";
        }
    }

    for(int i=0;i<26;i++)
    {
        if(trieTree->children[i] != NULL)
        {
            noChild=false;

            word.push_back(i+'a');
            lexicographicalPrint(trieTree, word);
            word.pop_back();
        }
    }
}

void dfs(struct node *trieTree, int &ans)
{
    ans += trieTree->occurrences.size();

    for(int i=0;i<26;i++)
    {
        if(trieTree->children[i]!=NULL)
        {
            dfs(trieTree->children[i], ans);
        }
    }

}

int searchOcc(struct node *trieNode, char *word)
{
    while(*word != '\0')
    {
        char ch = *word;
        if(trieNode->children[ch-'a']!=NULL)
        {
            trieNode = trieNode->children[ch-'a'];
            ++word;
        }
        else break;
    }

    if(*word == '\0')
    {
        int ans = 0;
        dfs(trieNode, ans);
        return ans;
    }
    else return 0;
}

int ct(struct node *trieNode, char *word)
{
    int ans=0;
    while(*word != '\0')
    {
        if(trieNode->children[*word -'a']!=NULL)
        {
            ans = trieNode->count[*word-'a'];
            trieNode = trieNode->children[*word-'a'];
        }
        else break;

        word++;
    }

    if(*word != '\0')
        return 0;
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
    node *trieTree = (struct node*)calloc(1, sizeof(struct node));

    int n;
    cin>>n;

    string opr;
    string s;
    char word[22];
    bool f=1;

    for(int i=0;i<n;i++)
    {
        cin>>s;

        for(int i=0;i<=s.length();i++)
            word[i] = s[i];

       f=f&insertWord(trieTree, word, 1);
    }
       if(f)
        cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}
