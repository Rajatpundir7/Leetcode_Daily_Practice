class Solution {
public:
        int n ;
        int m ;
        vector<string> result;
        vector<pair<int,int> > direction = { {1,0} , {0,1} , {-1,0}, {0,-1}};
    struct trienode{
        bool endword ;
        string word;
        trienode* child[26];
    };
    trienode * getnode(){
        trienode*newnode = new trienode();
        newnode->word ="";
        newnode->endword = false;
        for(int i =0 ;i < 26;i++){
            newnode->child[i] = NULL;
        }
        return newnode;
    }

    void insert(trienode* root, string word){
        trienode* craw = root;
        for(int i =0 ; i< word.length();i++){
            char ch = word[i];

            if(craw->child[ch-'a'] == NULL){
                craw->child[ch-'a'] = getnode();
            }
            craw = craw->child[ch-'a'];
            
        }
        craw->endword = true;
            craw->word = word;
    }
    void DFS(vector<vector<char>>& board ,int i , int j ,trienode*root){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }

        if(board[i][j] == '$' || root->child[board[i][j] -'a'] == NULL  ){
                return ;
        }

        root = root->child[board[i][j] -'a' ];
        if(root->endword == true){
            result.push_back(root->word);
            root->endword = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(pair<int,int> &dir : direction){
            int ni = i + dir.first;
            int nj = j + dir.second;

            DFS(board,ni,nj,root);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trienode* root = getnode();
        for(string &word : words){
            insert(root,word);
        }

        for(int i = 0 ;i< m;i++){
            for(int j =0 ;j < n;j++){
                char ch = board[i][j];

                if(root->child[ch-'a'] != NULL){
                    DFS(board,i,j,root);
                }
            }
        }
        return result;
    }
};