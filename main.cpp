#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include "tspvector.h"


int main()
{

  float t;

  char border[] = "------------------";

  printf("%30.28lf\n", ((double)TSP_PI));

  cVec A, B, C, D;

  printf("\n%sFriend Operators%s",border,border);
  A = Vec(1, 2, 3,"A");
  B = Vec(3, 2, 1,"B");

  (A + B).setName("A + B").Print();
  C.setName("A += B");
  C.Set(A) += B;
  C.Print();
  C.setName("A += 4");
  C.Set(A) += 4;
  C.Print();

  (A - B).setName("A - B").Print();
  C.setName("A -= B");
  C.Set(A) -= B;
  C.Print();
  C.setName("A -= 4");
  C.Set(A) -= 4;
  C.Print();

  (A ^ B).setName("A x B").Print();
  C.setName("A x= B");
  C.Set(A) ^= B;
  C.Print();

  (4 * A).setName("4 * A").Print();
  (A * 4).setName("A * 4").Print();
  C.setName("A *= 4");
  C.Set(A) *= 4;
  C.Print();
  C.setName("A = A.Mul(A * B)");
  C.Set(A) *= B;
  C.Print();

  (A / 2).setName("A / 2").Print();
  C.Set(A).setName("A /= 2") /= 2;
  C.Print();

  printf("\n A <  B: %d",A <  B);
  printf("\n A <= B: %d",A <= B);
  printf("\n A >  B: %d",A >  B);
  printf("\n A >= B: %d",A >= B);
  B = Vec(1, 2, 3,"B"); printf("\n A == B: %d",A == B);
  B = Vec(1, 3, 3,"B"); printf("\n A != B: %d",A != B);

  printf("\n%sStagePrint%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C.Set(A).setName("A").Print().Add(B).setName("A + B").Print().Div(4).setName("A / 4").Print();

  printf("\n%sIncrementsDecrements%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(0, 0, 0, "C");
  C.Set(A).setName("C++");
  C++;
  C.Print();
  C.Set(A).setName("C--");
  C--;
  C.Print();

  printf("\n%sDistance%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(0, 0, 0, "C");

  printf("\nRelative\n%30.28lf, \n%30.28lf",A.getDistance(B),A.getDistance(&B));
  printf("\nNoOrigin\n%30.28lf, \n%30.28lf",A.getDistance(NULL),A.getDistance());

  printf("\n%sCoplanarity%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(7, 8, 9, "C");
  printf("\nCoplan: %u",A.isCoplanar(&B,&C));
  printf("\nCoplan: %u",A.isCoplanar(B,C));
  printf("\nCoplan: %u",A.isCoplanar(B,&C));
  printf("\nCoplan: %u",A.isCoplanar(&B,C));


  printf("\n%sMixed Product%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(3, 5, 1, "C");
  printf("\nMix: %f",A.getMixed(B,C));
  printf("\nMix: %f",A.getMixed(&B,&C));
  printf("\nMix: %f",A.getMixed(&B,C));
  printf("\nMix: %f",A.getMixed(B,&C));


  printf("\n%sOrthogonality%s",border,border);
  A = Vec(1,  2,  3, "A");
  B = Vec(5, -1, -1, "B");
  printf("\nOrth: %u, %u",A.isOrthogonal(B),A.isOrthogonal(&B));

  printf("\n%sCollinearity%s",border,border);
  A = Vec( 1,  2,  3, "A");
  B = Vec(-2, -4, -6, "B");
  printf("\nColl: %u, %u",A.isCollinear(B), A.isCollinear(&B));

  printf("\n%sSwapping%s",border,border);
  A.getSwap("xy").Print();
  A.getSwap("xY").Print();
  A.getSwap("Xy").Print();
  A.getSwap("XY").Print();
  C.Set(A).Swap("xy").Print();
  C.Set(A).Swap("xY").Print();
  C.Set(A).Swap("Xy").Print();
  C.Set(A).Swap("XY").Print();

  printf("\n%sDirection%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getDirection().Print();
  A.getDirection(NULL).Print();
  C.Set(A).Direction().Print();
  C.Set(A).Direction(NULL).Print();

  printf("\n%sDirection origin%s",border,border);
  A.getDirection(B).Print();
  A.getDirection(&B).Print();
  C.Set(A).Direction(B).Print();
  C.Set(A).Direction(&B).Print();

  printf("\n%sProject%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getProject(&B).Print();
  A.getProject( B).Print();
  C.Set(A).Project(&B).Print();
  C.Set(A).Project( B).Print();


  printf("\n%sAngles%s",border,border);
  printf("\n%f, %f, %f, %f",A.getAngleDeg(B),A.getAngleDeg(&B),A.getAngleRad(&B),A.getAngleRad(B));

  printf("\n%sDivide%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getDiv(2).Print();
  C.Set(&A).Div(2).Print();
  C.Set(&A) /= 2;
  C.Print();
  C = A / 2;
  C.Print();

  printf("\n%sMultiply%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getMul(2).Print();
  C.Set(&A).Mul(2).Print();
  C.Set(&A) *= 2;
  C.Print();
  C = A * 2;
  C.Print();

  printf("\n%sSubstract%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getSub(&B).Print();
  A.getSub (B).Print();
  C.Set(&A).Sub(B).Print();
  C.Set(&A).Sub(&B).Print();
  C.Set(&A) -= B;
  C.Print();
  C = A - B;
  C.Print();

  printf("\n%sAddition%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getAdd(&B).Print();
  A.getAdd (B).Print();
  C.Set(&A).Add(B).Print();
  C.Set(&A).Add(&B).Print();
  C.Set(&A) += B;
  C.Print();
  C = A + B;
  C.Print();

  printf("\n%sCross%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec("C");
  A.getCross(&B).Print();
  A.getCross (B).Print();
  C.Set(&A).Cross(B).Print();
  C.Set(&A).Cross(&B).Print();
  C.Set(&A) ^= B;
  C.Print();
  C = A ^ B;
  C.Print();

  printf("\n%sTriple cross product%s",border,border);

  A = Vec(1,  2, 3, "A");
  B = Vec(1, -3, 4, "B");
  C = Vec(2,  4,-2, "C");
  D = Vec(0,0,0,"D");

  D.Set(A).CrossTriple(B,C).Print();
  D.Set(A).CrossTriple(B,&C).Print();
  D.Set(A).CrossTriple(&B,C).Print();
  D.Set(A).CrossTriple(&B,&C).Print();
  D = A.getCrossTriple(B,C); D.Print();
  D = A.getCrossTriple(B,&C); D.Print();
  D = A.getCrossTriple(&B,C); D.Print();
  D = A.getCrossTriple(&B,&C); D.Print();

  printf("\n%sArea%s",border,border);
  A = Vec(1,  2, 3, "A");
  B = Vec(3,  2, 1, "B");
  C = Vec(4,-10, 4, "C");
  printf("\nTri = \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getAreaTriangle(B),
         A.getAreaTriangle(&B),
         A.getAreaTriangle(NULL));
  printf("\nPar = \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getAreaParallelogram(B),
         A.getAreaParallelogram(&B),
         A.getAreaParallelogram(NULL));

  printf("\n%sVolume%s",border,border);
  printf("\nHyd = \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getVolumeTetrahedron(B,C),
         A.getVolumeTetrahedron(&B,&C),
         A.getVolumeTetrahedron(&B,C),
         A.getVolumeTetrahedron(B,&C),
         A.getVolumeTetrahedron(NULL,C),
         A.getVolumeTetrahedron(B,NULL),
         A.getVolumeTetrahedron(NULL,NULL));
  printf("\nPara = \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getVolumeParallelepiped(B,C),
         A.getVolumeParallelepiped(&B,&C),
         A.getVolumeParallelepiped(&B,C),
         A.getVolumeParallelepiped(B,&C),
         A.getVolumeParallelepiped(NULL,C),
         A.getVolumeParallelepiped(B,NULL),
         A.getVolumeParallelepiped(NULL,NULL));

  printf("\n%sUser data%s",border,border);

  int b = 6;

  struct test
  {
    int a;
    int b;
    int c;
    char name[100];
  };

  struct test Test;
  B = Vec(7.376732e-039, -3, 4, "B");
  Test.a = 1;
  Test.b = 10;
  Test.c = 100;
  strcpy(Test.name,"I will not throw paper in class !");

  A.setUser(&b);
  B.setUser(&Test);
  C.setUser(&B);

  printf("\nTreat the user data in A as a binary integer: %d",*(int *)A.getUser());
  printf("\nTreat the user data in B as (struct test *) : %s",((struct test *)B.getUser())->name);
  printf("\nTreat the user data in C as a vector then get its user data as integer: %d",((struct test *)(((cVec *)C.getUser())->getUser()))->c);
  printf("\nTreat the address of the user data of C as char: <%s> %d",(char*)((cVec *)C.getUser()),*((int *)&B));

  printf("\n%sPost Increment%s",border,border);
  A = Vec(1,0,0,"A");
  B = Vec(2,0,0,"B");

  (A++).setName("A++").Print();
  A.setName("A Print").Print();
  (B--).setName("B--").Print();
  B.setName("B Print").Print();

  printf("\n%sNegate%s",border,border);
  A = Vec(1,1,1,"A");
  B.Set(A).Neg().Print();
  A.getNeg().Print();

  printf("\n%sOffset%s",border,border);
  t = sqrt(3);
  A = Vec(1,1,1,"A");
  B.Set(A).Offset(A,t).Print();
  B.Set(A).Offset(&A,t).Print();
  A.getOffset(A,t).Print();
  A.getOffset(&A,t).Print();

  printf("\n");

  int i=10;
  A.Set(1,1,1);
  A.Direction();
  A.Mul(i-1);
  while(i)
  {
    A.RoundDigit(5).Print();
    cVec B = A.getDirection();
    if(!B.isValid()){ printf("\nLength is zero [%d]",i); break; }
    A--;
    i--;
    A.Print();
  }

  return 0;
}







