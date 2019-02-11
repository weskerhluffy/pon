/*
 ============================================================================
 Name        : pon.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// XXX: https://www.spoj.com/problems/PON/
// XXX: https://prrateekk.wordpress.com/2016/03/14/miller-rabin-probabilistic-primality-algorithm/
#if 1
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stddef.h>
#ifndef ONLINE_JUDGE
#include <unistd.h>
#include <sys/time.h>
#endif
#include <math.h>
#include <stdint.h>
#include <ctype.h>


#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#else
#include <time.h>
#include <stdarg.h>
#endif

#if 1
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LONG_MAX
#endif

#ifndef ULONG_LONG_MAX
#define ULONG_LONG_MAX ULONG_MAX
#endif



#define COMUN_ASSERT_DUROTE 0
#define COMUN_ASSERT_SUAVECITO 1
#define COMUN_ASSERT_NIMADRES 2

#define CFST static

typedef char byteme;
typedef unsigned int nat;
typedef nat tipo_dato;
typedef long long entero_largo;
typedef unsigned long long elss;
typedef long long bitch_vector;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;

#define COMUN_TIPO_ASSERT COMUN_ASSERT_DUROTE

#define assert_timeout_dummy(condition) 0;

#if COMUN_TIPO_ASSERT == COMUN_ASSERT_DUROTE
#define assert_timeout(condition) assert(condition);
#endif
#if COMUN_TIPO_ASSERT == COMUN_ASSERT_SUAVECITO
#define assert_timeout(condition) if(!(condition)){while(1){printf("");};abort();}
#endif
#if COMUN_TIPO_ASSERT == COMUN_ASSERT_NIMADRES
#define assert_timeout(condition) 0
#endif


#define comun_max(x,y) ((x) < (y) ? (y) : (x))
#define comun_min(x,y) ((x) < (y) ? (x) : (y))

#define comun_calloc_local(tipo) (&(tipo){0})


#endif

#define COMUN_LIMPIA_MEM(m,s) (memset(m,0,s))
#define COMUN_LIMPIA_MEM_STATICA(m) (memset(m,0,sizeof(*(m))))


#define comun_compara_tipo(tipo) CFST int comun_compara_##tipo(const void *pa, const void *pb) { \
	int r = 0; \
	tipo a = *(tipo *)pa; \
	tipo b = *(tipo *)pb; \
	if (a < b) { \
		r = -1; \
	} else { \
		if (a > b) { \
			r = 1; \
		} \
	} \
	return r; \
}

#endif

#if 1
CFST elss pon_mul_mod(elss a,
		elss b, elss c) {
	entero_largo x = 0, y = a % c;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x + y) % c;
		}
		y = (y * 2) % c;
		b /= 2;
	}
	return x % c;
}

// TODO: Cambiar por iterativa
CFST elss pon_exp_mod(elss a,
		elss p, elss m) {
	if (!p) {
		return 1;
	}
	if (p & 1) {
		return pon_mul_mod(a, pon_exp_mod(a, p - 1, m), m);
	}
	entero_largo x = pon_exp_mod(a, p >> 1, m);
	return pon_mul_mod(x, x, m);
}

// XXX: https://stackoverflow.com/questions/2509679/how-to-generate-a-random-integer-number-from-within-a-range
CFST elss pon_rand(elss max) {
	elss
	// max <= RAND_MAX < ULONG_MAX, so this is okay.
	num_bins = (elss) max + 1, num_rand =
			(((elss) RAND_MAX) << 32 | (0xffffffff)) + 1,
			bin_size = num_rand / num_bins, defect = num_rand % num_bins;

	elss x;
	do {
		x = random();
	}
	// This is carefully written not to overflow
	while (num_rand - defect <= (elss) x);

	// Truncated division is intentional
	return x / bin_size;
}

CFST elss pon_rand_intervalo(
		elss min, elss max) {
	;
	return (elss) min + pon_rand(max - min);
}

CFST bool pon_prueba_miller_rabbit(elss n) {
	elss a = pon_rand_intervalo(2, n - 2);
	elss d = n - 1;
	while (!(d & 1)) {
		d >>= 1;
	}
	elss x = pon_exp_mod(a, d, n);

	if (x == 1 || x == (n - 1)) {
		return verdadero;
	}
	while (d != (n - 1)) {
		x = pon_mul_mod(x, x, n);
		d <<= 1;
		if (x == 1) {
			return falso;
		}
		if (x == (n - 1)) {
			return verdadero;
		}
	}
	return falso;
}

CFST bool pon_es_primo(elss n, nat k) {
	if (n <= 1 || n == 4) {
		return falso;
	}
	if (n <= 3) {
		return verdadero;
	}

	while (k--) {
		if (!pon_prueba_miller_rabbit(n)) {
			return falso;
		}
	}
	return verdadero;
}

CFST void pon_main() {
	nat t = 0;
	scanf("%u\n", &t);
	while (t--) {
		elss n = 0;
		scanf("%llu\n", &n);
		bool r = pon_es_primo(n, 300);
		char *rs = NULL;
		if (r) {
			rs = "YES";
		} else {
			rs = "NO";
		}
		printf("%s\n", rs);
	}
}

#endif

int main(void) {
	pon_main();
	return EXIT_SUCCESS;
}
