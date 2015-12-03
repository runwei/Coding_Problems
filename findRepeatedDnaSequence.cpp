vector<string> findRepeatedDnaSequences(string s) {
    char m_set[1048576] {-1};
    unordered_map<char,int> m_map;
    m_map['A']=0;m_map['T']=1;m_map['C']=2;m_map['G']=3;
    string m_map2 ("ATCG");
    vector<string> ret;
    if (s.size()<11) return ret;
    int num=0;
    for (int i=0;i<10;++i) num=4*num+m_map[s[i]];
    m_set[num]=0;
    for (int i=10;i<s.size();i++) {
        num=(num*4+m_map[s[i]])%1048576;
        m_set[num]=i;
    }
    for (int i=0;i<s.size();++i)
        if (m_set[i]!=-1)  {
            ret.push_back(s.substr(i,10));
        }
    return ret;
}