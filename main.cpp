#include "tspvector.h"

int main()
{
  float t = 0;
  char border[] = "------------------";

  printf("%30.28lf\n", ((double)TSP_PI));

  cVec A, B, C, D;
  A = Vec(1, 2, 3,"A");
  B = Vec(3, 2, 1,"B");

  printf("\n%sFriend Operators%s",border,border);
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

  printf("\n%sCompare Operators%s",border,border);
  A.Print();
  B.Print();

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

  A.setName("A Print").Print();
  (A++).setName("A++").Print();
  A.setName("A Print").Print();
  (++A).setName("++A").Print();

  B.setName("B Print").Print();
  (B--).setName("B--").Print();
  B.setName("B Print").Print();
  (--B).setName("--B").Print();

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

  printf("\n%sNumber ops%s",border,border);
  A = Vec(1.12345,1.34567,1.56789,"A");
  A.Print();
  B.Set(A).setName("0").RoundDigit(0).Print();
  B.Set(A).setName("1").RoundDigit(1).Print();
  B.Set(A).setName("2").RoundDigit(2).Print();
  B.Set(A).setName("3").RoundDigit(3).Print();
  printf("\n");

  setError("%s %d","sfsdf ",6); // Test static

  printf("\n%sError handling%s <%s>",border,border,getError());
  A.Set(0,0,0).Direction();
  if(!hasError()){ printf("\nOK."); }
  else{ printf("\nFailed Direction: %s",getError()); clrError(); }
  A.Set(1,1,1) /= 0;
  if(!hasError()){ printf("\nOK."); }
  else{ printf("\nFailed /=: %s",getError()); clrError(); }
  A.Set(0,0,0);
  t = A.getAngleRad(B);
  if(!hasError()){ printf("\nOK. %14.4f",t); }
  else{ printf("\nFailed getAngleRad: %s",getError()); clrError(); }
  A.Swap("yx");
  if(!hasError()){ A.Print(); printf(" OK."); }
  else{ printf("\nFailed: %s",getError()); clrError(); }
  A.Swap("ax");
  if(!hasError()){ A.Print(); }
  else{ printf("\nFailed Swap: %s",getError()); clrError(); }

  A = Vec(1,  2, 3, "A");
  B = Vec(3,  2, 1, "B");
  C = Vec(4,-10, 4, "C");

  printf("\n%sgetAreaTriangle%s",border,border);
  printf("\nA.getAreaTriangle(B) = %30.28lf",A.getAreaTriangle(B));
  printf("\nA.getAreaTriangle(&B) = %30.28lf",A.getAreaTriangle(&B));
  printf("\nA.getAreaTriangle(NULL) = %30.28lf",A.getAreaTriangle(NULL));

  printf("\n%sgetAreaParallelogram%s",border,border);
  printf("\nA.getAreaParallelogram(B) = %30.28lf",A.getAreaParallelogram(B));
  printf("\nA.getAreaParallelogram(&B) = %30.28lf",A.getAreaParallelogram(&B));
  printf("\nA.getAreaParallelogram(NULL) = %30.28lf",A.getAreaParallelogram(NULL));

  printf("\n%sVolumeTetrahedron%s",border,border);
  printf("\ngetVolumeTetrahedron(B,C) = %30.28lf",A.getVolumeTetrahedron(B,C));
  printf("\ngetVolumeTetrahedron(&B,&C) = %30.28lf",A.getVolumeTetrahedron(&B,&C));
  printf("\ngetVolumeTetrahedron(&B,C) = %30.28lf",A.getVolumeTetrahedron(&B,C));
  printf("\ngetVolumeTetrahedron(B,&C) = %30.28lf",A.getVolumeTetrahedron(B,&C));
  printf("\ngetVolumeTetrahedron(NULL,C) = %30.28lf",A.getVolumeTetrahedron(NULL,C));
  printf("\ngetVolumeTetrahedron(B,NULL) = %30.28lf",A.getVolumeTetrahedron(B,NULL));
  printf("\ngetVolumeTetrahedron(NULL,NULL) = %30.28lf",A.getVolumeTetrahedron(NULL,NULL));

  printf("\n%sVolumeParallelepiped%s",border,border);
  printf("\ngetVolumeParallelepiped(B,C) = %30.28lf",A.getVolumeParallelepiped(B,C));
  printf("\ngetVolumeParallelepiped(&B,&C) = %30.28lf",A.getVolumeParallelepiped(&B,&C));
  printf("\ngetVolumeParallelepiped(&B,C) = %30.28lf",A.getVolumeParallelepiped(&B,C));
  printf("\ngetVolumeParallelepiped(B,&C) = %30.28lf",A.getVolumeParallelepiped(B,&C));
  printf("\ngetVolumeParallelepiped(NULL,C) = %30.28lf",A.getVolumeParallelepiped(NULL,C));
  printf("\ngetVolumeParallelepiped(B,NULL) = %30.28lf",A.getVolumeParallelepiped(B,NULL));
  printf("\ngetVolumeParallelepiped(NULL,NULL) = %30.28lf",A.getVolumeParallelepiped(NULL,NULL));

  return 0;
}
