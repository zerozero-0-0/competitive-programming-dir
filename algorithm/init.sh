#!/bin/bash

read -p "コンテスト名を入力してください : " name
mkdir $name
cd $name
touch {a..f}.cpp

for file in {a..f}.cpp; do
  cat << EOF > $file
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
constexpr int iinf = INT_MAX;
constexpr long long linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
EOF
done

echo "$name の作成に成功しました"
