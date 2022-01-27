#pragma once
#define NumSets 10
typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElemenType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElemenType X, DisjSet S);
