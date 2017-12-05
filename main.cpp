#include "tspvector.h"

int main()
{
  FILE *f = NULL;
  char name[] = "E:\\Documents\\CodeBlocks-Projs\\TSP\\out.txt";
  //char name[] = "";
  if(name[0] != '\0')
  {
    f = fopen(name,"wt+");
    f = (f == NULL) ? stdout : f;
  }else{ f = stdout; }
  float t = 0;
  char border[] = "------------------";
  fprintf(f,"%30.28lf\n", ((double)TSP_PI));

  cVec A, B, C, D, E;
  A = Vec(1, 2, 3,"A");
  B = Vec(3, 2, 1,"B");

  fprintf(f,"\n%sStringConversion%s",border,border);
  fprintf(f,"\n%s",A.getString("%30.28lf"));

  fprintf(f,"\n%sFriend Operators%s",border,border);
  (A + B).setName("A + B").Print(f);
  C.setName("A += B");
  C.Set(A) += B;
  C.Print(f);
  C.setName("A += 4");
  C.Set(A) += 4;
  C.Print(f);

  (A - B).setName("A - B").Print(f);
  C.setName("A -= B");
  C.Set(A) -= B;
  C.Print(f);
  C.setName("A -= 4");
  C.Set(A) -= 4;
  C.Print(f);

  (A ^ B).setName("A x B").Print(f);
  C.setName("A x= B");
  C.Set(A) ^= B;
  C.Print(f);

  (4 * A).setName("4 * A").Print(f);
  (A * 4).setName("A * 4").Print(f);
  C.setName("A *= 4");
  C.Set(A) *= 4;
  C.Print(f);
  C.setName("A = A.Mul(A * B)");
  C.Set(A) *= B;
  C.Print(f);

  (A / 2).setName("A / 2").Print(f);
  C.Set(A).setName("A /= 2") /= 2;
  C.Print(f);

  fprintf(f,"\n%sCompare Operators%s",border,border);
  A.Print(f);
  B.Print(f);

  fprintf(f,"\n A <  B: %d",A <  B);
  fprintf(f,"\n A <= B: %d",A <= B);
  fprintf(f,"\n A >  B: %d",A >  B);
  fprintf(f,"\n A >= B: %d",A >= B);
  B = Vec(1, 2, 3,"B"); fprintf(f,"\n A == B: %d",A == B);
  B = Vec(1, 3, 3,"B"); fprintf(f,"\n A != B: %d",A != B);

  fprintf(f,"\n%sStagePrint%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C.Set(A).setName("A").Print(f).Add(B).setName("A + B").Print(f).Div(4).setName("A / 4").Print(f);

  fprintf(f,"\n%sDistance%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(0, 0, 0, "C");

  fprintf(f,"\nRelative\n%30.28lf, \n%30.28lf",A.getDistance(B),A.getDistance(&B));
  fprintf(f,"\nNoOrigin\n%30.28lf, \n%30.28lf",A.getDistance(NULL),A.getDistance());

  fprintf(f,"\n%sCoplanarity%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(7, 8, 9, "C");
  fprintf(f,"\nCoplan: %u",A.isCoplanar(&B,&C));
  fprintf(f,"\nCoplan: %u",A.isCoplanar(B,C));
  fprintf(f,"\nCoplan: %u",A.isCoplanar(B,&C));
  fprintf(f,"\nCoplan: %u",A.isCoplanar(&B,C));


  fprintf(f,"\n%sMixed Product%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(4, 5, 6, "B");
  C = Vec(3, 5, 1, "C");
  fprintf(f,"\nMix: %f",A.getMixed(B,C));
  fprintf(f,"\nMix: %f",A.getMixed(&B,&C));
  fprintf(f,"\nMix: %f",A.getMixed(&B,C));
  fprintf(f,"\nMix: %f",A.getMixed(B,&C));


  fprintf(f,"\n%sOrthogonality%s",border,border);
  A = Vec(1,  2,  3, "A");
  B = Vec(5, -1, -1, "B");
  fprintf(f,"\nOrth: %u, %u",A.isOrthogonal(B),A.isOrthogonal(&B));

  fprintf(f,"\n%sCollinearity%s",border,border);
  A = Vec( 1,  2,  3, "A");
  B = Vec(-2, -4, -6, "B");
  fprintf(f,"\nColl: %u, %u",A.isCollinear(B), A.isCollinear(&B));

  fprintf(f,"\n%sSwapping%s",border,border);
  A.getSwap("xy").Print(f);
  A.getSwap("xY").Print(f);
  A.getSwap("Xy").Print(f);
  A.getSwap("XY").Print(f);
  C.Set(A).Swap("xy").Print(f);
  C.Set(A).Swap("xY").Print(f);
  C.Set(A).Swap("Xy").Print(f);
  C.Set(A).Swap("XY").Print(f);

  fprintf(f,"\n%sDirection%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getDirection().Print(f);
  A.getDirection(NULL).Print(f);
  C.Set(A).Direction().Print(f);
  C.Set(A).Direction(NULL).Print(f);

  fprintf(f,"\n%sDirection origin%s",border,border);
  A.getDirection(B).Print(f);
  A.getDirection(&B).Print(f);
  C.Set(A).Direction(B).Print(f);
  C.Set(A).Direction(&B).Print(f);

  fprintf(f,"\n%sProject%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getProject(&B).Print(f);
  A.getProject( B).Print(f);
  C.Set(A).Project(&B).Print(f);
  C.Set(A).Project( B).Print(f);

  fprintf(f,"\n%sAngles%s",border,border);
  fprintf(f,"\n%f, %f, %f, %f",A.getAngleDeg(B),A.getAngleDeg(&B),A.getAngleRad(&B),A.getAngleRad(B));

  fprintf(f,"\n%sDivide%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getDiv(2).Print(f);
  C.Set(&A).Div(2).Print(f);
  C.Set(&A) /= 2;
  C.Print(f);
  C = A / 2;
  C.Print(f);

  fprintf(f,"\n%sMultiply%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getMul(2).Print(f);
  C.Set(&A).Mul(2).Print(f);
  C.Set(&A) *= 2;
  C.Print(f);
  C = A * 2;
  C.Print(f);

  fprintf(f,"\n%sSubstract%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getSub(&B).Print(f);
  A.getSub (B).Print(f);
  C.Set(&A).Sub(B).Print(f);
  C.Set(&A).Sub(&B).Print(f);
  C.Set(&A) -= B; C.Print(f);
  C = A - B; C.Print(f);
  C.Set(&A).Sub(10).Print(f);
  C.Set(&A).Sub(10,10).Print(f);
  C.Set(&A).Sub(10,10,10).Print(f);

  fprintf(f,"\n%sAddition%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec(0, 0, 0, "C");
  A.getAdd(&B).Print(f);
  A.getAdd (B).Print(f);
  C.Set(&A).Add(B).Print(f);
  C.Set(&A).Add(&B).Print(f);
  C.Set(&A) += B; C.Print(f);
  C = A + B; C.Print(f);
  C.Set(&A).Add(10).Print(f);
  C.Set(&A).Add(10,10).Print(f);
  C.Set(&A).Add(10,10,10).Print(f);

  fprintf(f,"\n%sCross%s",border,border);
  A = Vec(1, 2, 3, "A");
  B = Vec(3, 2, 1, "B");
  C = Vec("C");
  A.getCross(&B).Print(f);
  A.getCross (B).Print(f);
  C.Set(&A).Cross(B).Print(f);
  C.Set(&A).Cross(&B).Print(f);
  C.Set(&A) ^= B;
  C.Print(f);
  C = A ^ B;
  C.Print(f);

  fprintf(f,"\n%sCenter point%s",border,border);
  A = Vec(30, 0, 0, "A");
  B = Vec(10, 0, 0, "B"); // Uncomment "TEST" to try it out
  E = Vec(30, 0, 0, "E"); B.setNext(&E);
  C = Vec("C");
  C.Set(A).Center(B).setName("a.Center(b)").Print(f);
  C.Set(A).Center(&B).setName("a.Center(*b)").Print(f);
  A.getCenter(B).setName("v a.Center(b)").Print(f);
  A.getCenter(&B).setName("v a.Center(*b)").Print(f);
  C = A % B; C.setName("A % B").Print(f);
  C = A % B.getX(); C.setName("A % B.x").Print(f);
  C = A.getX() % B; C.setName("A.x % B").Print(f);
  C.Set(A); C %= B; C.setName("C %= B").Print(f);
  C.Set(A); C %= B.getX(); C.setName("C %= B.x").Print(f);

  fprintf(f,"\n%sTriple cross product%s",border,border);

  A = Vec(1,  2, 3, "A");
  B = Vec(1, -3, 4, "B");
  C = Vec(2,  4,-2, "C");
  D = Vec(0,0,0,"D");

  D.Set(A).CrossTriple(B,C).Print(f);
  D.Set(A).CrossTriple(B,&C).Print(f);
  D.Set(A).CrossTriple(&B,C).Print(f);
  D.Set(A).CrossTriple(&B,&C).Print(f);
  D = A.getCrossTriple(B,C); D.Print(f);
  D = A.getCrossTriple(B,&C); D.Print(f);
  D = A.getCrossTriple(&B,C); D.Print(f);
  D = A.getCrossTriple(&B,&C); D.Print(f);

  fprintf(f,"\n%sUser data%s",border,border);
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

  fprintf(f,"\nTreat the user data in A as a binary integer: %d",*(int *)A.getUser());
  fprintf(f,"\nTreat the user data in B as (struct test *) : %s",((struct test *)B.getUser())->name);
  fprintf(f,"\nTreat the user data in C as a vector then get its user data as integer: %d",((struct test *)(((cVec *)C.getUser())->getUser()))->c);
  fprintf(f,"\nTreat the address of the user data of C as char: <%s> %d",(char*)((cVec *)C.getUser()),*((int *)&B));

  fprintf(f,"\n%sPost Increment%s",border,border);
  A = Vec(1,0,0,"A");
  B = Vec(2,0,0,"B");

  A.setName("A Print").Print(f);
  (A++).setName("A++").Print(f);
  A.setName("A Print").Print(f);
  (++A).setName("++A").Print(f);

  B.setName("B Print").Print(f);
  (B--).setName("B--").Print(f);
  B.setName("B Print").Print(f);
  (--B).setName("--B").Print(f);

  fprintf(f,"\n%sNegate%s",border,border);
  A = Vec(1,1,1,"A");
  B.Set(A).Neg().Print(f);
  A.getNeg().Print(f);

  fprintf(f,"\n%sOffset%s",border,border);
  t = sqrt(3);
  A = Vec(1,1,1,"A");
  B.Set(A).Offset(A,t).Print(f);
  B.Set(A).Offset(&A,t).Print(f);
  A.getOffset(A,t).Print(f);
  A.getOffset(&A,t).Print(f);

  fprintf(f,"\n%sNumber ops%s",border,border);
  A = Vec(1.12345,1.34567,1.56789,"A");
  A.Print(f);
  B.Set(A).setName("0").RoundDigit(0).Print(f);
  B.Set(A).setName("1").RoundDigit(1).Print(f);
  B.Set(A).setName("2").RoundDigit(2).Print(f);
  B.Set(A).setName("3").RoundDigit(3).Print(f);
  fprintf(f,"\n");

  // ..TSP\tspvector.h|225|error: 'void Vec::setError(const char*, ...)' is protected|
  // A.setError("asdad");

  fprintf(f,"\n%sError handling%s",border,border);
  fprintf(f,"\nError <%s>",A.getError());
  A.Set(0,0,0).Direction();
  if(!A.hasError()){ fprintf(f,"\nOK."); }
  else{ fprintf(f,"\nFailed Direction: %s",A.getError()); A.clrError(); }
  A.Set(1,1,1) /= 0;
  if(!A.hasError()){ fprintf(f,"\nOK."); }
  else{ fprintf(f,"\nFailed /=: %s",A.getError()); A.clrError(); }
  A.Set(0,4,5);
  t = A.getAngleRad(B);
  if(!A.hasError()){ fprintf(f,"\nOK. %14.4f",t); }
  else{ fprintf(f,"\nFailed getAngleRad: %s",A.getError()); A.clrError(); }
  A.Swap("yx");
  if(!A.hasError()){ A.Print(f); fprintf(f," OK."); }
  else{ fprintf(f,"\nFailed: %s",A.getError()); A.clrError(); }
  A.Swap("ax");
  if(!A.hasError()){ A.Print(f); }
  else{ fprintf(f,"\nFailed Swap: %s",A.getError()); A.clrError(); }

  A = Vec(1,  2, 3, "A");
  B = Vec(3,  2, 1, "B");
  C = Vec(4,-10, 4, "C");

  fprintf(f,"\n%sgetAreaTriangle%s",border,border);
  fprintf(f,"\nA.getAreaTriangle(B)    = %30.28lf",A.getAreaTriangle(B));
  fprintf(f,"\nA.getAreaTriangle(&B)   = %30.28lf",A.getAreaTriangle(&B));
  fprintf(f,"\nA.getAreaTriangle(NULL) = %30.28lf",A.getAreaTriangle(NULL));

  fprintf(f,"\n%sgetAreaParallelogram%s",border,border);
  fprintf(f,"\nA.getAreaParallelogram(B)    = %30.28lf",A.getAreaParallelogram(B));
  fprintf(f,"\nA.getAreaParallelogram(&B)   = %30.28lf",A.getAreaParallelogram(&B));
  fprintf(f,"\nA.getAreaParallelogram(NULL) = %30.28lf",A.getAreaParallelogram(NULL));

  fprintf(f,"\n%sVolumeTetrahedron%s",border,border);
  fprintf(f,"\ngetVolumeTetrahedron(B,C)       = %30.28lf",A.getVolumeTetrahedron(B,C));
  fprintf(f,"\ngetVolumeTetrahedron(&B,&C)     = %30.28lf",A.getVolumeTetrahedron(&B,&C));
  fprintf(f,"\ngetVolumeTetrahedron(&B,C)      = %30.28lf",A.getVolumeTetrahedron(&B,C));
  fprintf(f,"\ngetVolumeTetrahedron(B,&C)      = %30.28lf",A.getVolumeTetrahedron(B,&C));
  fprintf(f,"\ngetVolumeTetrahedron(NULL,C)    = %30.28lf",A.getVolumeTetrahedron(NULL,C));
  fprintf(f,"\ngetVolumeTetrahedron(B,NULL)    = %30.28lf",A.getVolumeTetrahedron(B,NULL));
  fprintf(f,"\ngetVolumeTetrahedron(NULL,NULL) = %30.28lf",A.getVolumeTetrahedron(NULL,NULL));

  fprintf(f,"\n%sVolumeParallelepiped%s",border,border);
  fprintf(f,"\ngetVolumeParallelepiped(B,C)       = %30.28lf",A.getVolumeParallelepiped(B,C));
  fprintf(f,"\ngetVolumeParallelepiped(&B,&C)     = %30.28lf",A.getVolumeParallelepiped(&B,&C));
  fprintf(f,"\ngetVolumeParallelepiped(&B,C)      = %30.28lf",A.getVolumeParallelepiped(&B,C));
  fprintf(f,"\ngetVolumeParallelepiped(B,&C)      = %30.28lf",A.getVolumeParallelepiped(B,&C));
  fprintf(f,"\ngetVolumeParallelepiped(NULL,C)    = %30.28lf",A.getVolumeParallelepiped(NULL,C));
  fprintf(f,"\ngetVolumeParallelepiped(B,NULL)    = %30.28lf",A.getVolumeParallelepiped(B,NULL));
  fprintf(f,"\ngetVolumeParallelepiped(NULL,NULL) = %30.28lf",A.getVolumeParallelepiped(NULL,NULL));

  fprintf(f,"\n%sRollL%s",border,border);
  C.Set(A).RollL().Print(f);
  A.getRollL().Print(f);

  fprintf(f,"\n%sRollR%s",border,border);
  C.Set(A).RollR().Print(f);
  A.getRollR().Print(f);

  fprintf(f,"\n%sShiftL%s",border,border);
  C.Set(A).ShiftL().Print(f);
  A.getShiftL().Print(f);

  fprintf(f,"\n%sShiftR%s",border,border);
  C.Set(A).ShiftR().Print(f);
  A.getShiftR().Print(f);

  fprintf(f,"\n%sCosine%s",border,border);
  fprintf(f,"\n{ %30.28lf , %30.28lf }",A.getCosine('x'),A.getCosine('X'));

  fclose(f);

  return 0;
}
