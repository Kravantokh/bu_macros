/* Benoe's Utilities: Macros
 * Main (and only) header */

/************************************* Portablity macros ***************************************/

#ifdef __clang__
/* Clang is the active compiler */


#elif defined(__GNUC__) || defined(__GNUG__)
/* GCC is the active compiler */


#elif defined(_MSC_VER)
/* MSVC is the active compiler - These macros are unchecked since I do not use MSVC */


#endif
/********************************** Settings set macros ****************************************/

/* Should everything just shut up and not change program flow at all?
 * (NOTE: Not recommended for development. May improve performance in release builds) */
#ifdef BU_NO_FEEDBACK
	#define BU_ERROR_MESSAGES false
	#define BU_RUNTIME_CHECKS false
	#define BU_TERMINATE(...)
#endif

#ifdef BU_ALL_MACROS
	#define BU_ERROR_MESSAGES true
	#define BU_RUNTIME_CHECKS true
#endif

/********************************** Program flow macros ****************************************/

/* Should error messages be printed? */
#ifndef BU_ERROR_MESSAGES
	#define BU_ERROR_MESSAGES true
#endif

/* Should critical errors terminate the application? */
#ifndef BU_RUNTIME_CHECKS
	#define BU_RUNTIME_CHECKS true
#endif

#ifndef BU_TERMINATE
	#define BU_TERMINATE(X) exit(X);
#endif

/*************************** Implementations of program flow macros ****************************/
/* A global error function
 * May be replaced by defining the BU_ERROR_MESSAGES macro which take arguments in the same manner as printf. */
#if BU_ERROR_MESSAGES
	#ifndef BU_ERR_FUNC
		#define BU_ERR_FUNC(...) fprintf(stderr, __VA_ARGS__);
	#endif
#else
	#ifndef BU_ERR_FUNC
		#define BU_ERR_FUNC(...)
	#endif

#endif /* BU_ERROR_MESSAGES*/


#if BU_RUNTIME_CHECKS
/* Null checking on pointer. If the given value is null show error and stop the program. If error messages are suppressed the program should still stop */
/* EXITPOINT 13 */
#ifndef BU_NULLCHECK
	#define BU_NULLCHECK(A)\
		if( (A) == NULL){\
			BU_ERR_FUNC("This should not be a null pointer at %s:%d ", __FILE__, __LINE__);\
			BU_TERMINATE(13);\
		}
#endif

#endif /* BU_RUNTIME_CHECKS */
