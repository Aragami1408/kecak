#include <stdio.h>

#include "base/base.h"


typedef struct TestStruct {
	int a;
	int b;
	int c;
	int d;
} TestStruct;

#define EvalPrint(x) printf("%s = %d\n", #x, (i32)(x))
#define EvalPrintLL(x) printf("%s = %lld\n", #x, (i64)(x))
#define EvalPrintU(x) printf("%s = %u\n", #x, (u32)(x))
#define EvalPrintULL(x) printf("%s = %llu\n", #x, (u64)(x))
#define EvalPrintF(x) printf("%s = %f\n", #x, (f32)(x))
#define EvalPrintB(x) printf("%s = %s\n", #x, (char*)((x)?"true":"false"))

int main() {
	int foo[100];
	for(u32 i = 0; i < ArrayCount(foo); i++) {
		foo[i] = i;
	}

	EvalPrint(ArrayCount(foo));

	int bar[100];
	MemoryCopyArray(bar, foo);
	EvalPrint(bar[50]);
	EvalPrint(MemoryMatch(foo, bar, sizeof(foo)));
	MemoryZeroArray(bar);
	EvalPrint(bar[50]);

	EvalPrint(OffsetOfMember(TestStruct, a));
	EvalPrint(OffsetOfMember(TestStruct, b));
	EvalPrint(OffsetOfMember(TestStruct, c));
	EvalPrint(OffsetOfMember(TestStruct, d));

	TestStruct t = {1,2,3,4};
	EvalPrint(t.a);
	EvalPrint(t.d);
	MemoryZeroStruct(&t);
	EvalPrint(t.a);
	EvalPrint(t.d);

	EvalPrint(Min(1,10));
	EvalPrint(Min(100, 10));
	EvalPrint(Max(1,10));
	EvalPrint(Max(100, 10));
	EvalPrint(Clamp(1, 10, 100));
	EvalPrint(Clamp(1, 0, 100));
	EvalPrint(Clamp(1, 500, 100));

	EvalPrintF(inf_f32());
	EvalPrintF(neg_inf_f32());

	EvalPrintF(inf_f64());
	EvalPrintF(neg_inf_f64());

	EvalPrintF(abs_f32(-100));
	EvalPrintF(abs_f32(100));
	EvalPrintF(abs_f32(0));
	EvalPrintF(abs_f32(neg_inf_f32()));

	EvalPrintF(abs_f64(-100));
	EvalPrintF(abs_f64(100));
	EvalPrintF(abs_f64(0));
	EvalPrintF(abs_f64(neg_inf_f64()));

	EvalPrintF(sqrt_f32(100.f));
	EvalPrintF(sin_f32(100.f));
	EvalPrintF(cos_f32(100.f));
	EvalPrintF(tan_f32(100.f));

	EvalPrintF(sqrt_f64(100.f));
	EvalPrintF(sin_f64(100.f));
	EvalPrintF(cos_f64(100.f));
	EvalPrintF(tan_f64(100.f));

	EvalPrintF(lerp(0, 0.5f, 1.f));
	EvalPrintF(lerp(10.f, 0.5f, 100.f));
	EvalPrintF(unlerp(0, 0.3f, 1.f));
	EvalPrintF(unlerp(10.f, lerp(10.f, 0.5f, 100.f), 100.f));

	EvalPrintB(i2f32_intr_contains(i2f32(20, 20, 200, 200), v2f32(100, 199)));
	EvalPrintB(i2f32_intr_contains(i2f32(20, 20, 200, 200), v2f32(100, 201)));
	EvalPrintB(i2f32_intr_contains(i2f32(20, 20, 200, 200), v2f32(19, 199)));
	return 0;
}
