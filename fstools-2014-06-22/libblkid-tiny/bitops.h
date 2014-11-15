#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>

/*
 * Bit map related macros. Usually provided by libc.
 */
#include <sys/param.h>

#ifndef NBBY
# define NBBY            CHAR_BIT
#endif

#ifndef setbit
# define setbit(a,i)	((a)[(i)/NBBY] |= 1<<((i)%NBBY))
# define clrbit(a,i)	((a)[(i)/NBBY] &= ~(1<<((i)%NBBY)))
# define isset(a,i)	((a)[(i)/NBBY] & (1<<((i)%NBBY)))
# define isclr(a,i)	(((a)[(i)/NBBY] & (1<<((i)%NBBY))) == 0)
#endif

/*
 * Byte swab macros (based on linux/byteorder/swab.h)
 */
#define swab16(x) \
	((uint16_t)( \
		(((uint16_t)(x) & (uint16_t)0x00ffU) << 8) | \
		(((uint16_t)(x) & (uint16_t)0xff00U) >> 8) ))

#define swab32(x) \
	((uint32_t)( \
		(((uint32_t)(x) & (uint32_t)0x000000ffUL) << 24) | \
		(((uint32_t)(x) & (uint32_t)0x0000ff00UL) <<  8) | \
		(((uint32_t)(x) & (uint32_t)0x00ff0000UL) >>  8) | \
		(((uint32_t)(x) & (uint32_t)0xff000000UL) >> 24) ))

#define swab64(x) \
	((uint64_t)( \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x00000000000000ffULL) << 56) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x000000000000ff00ULL) << 40) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x0000000000ff0000ULL) << 24) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x00000000ff000000ULL) <<  8) | \
	        (uint64_t)(((uint64_t)(x) & (uint64_t)0x000000ff00000000ULL) >>  8) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x0000ff0000000000ULL) >> 24) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0x00ff000000000000ULL) >> 40) | \
		(uint64_t)(((uint64_t)(x) & (uint64_t)0xff00000000000000ULL) >> 56) ))


#if __BYTE_ORDER == __BIG_ENDIAN

#define cpu_to_le16(x) swab16(x)
#define cpu_to_le32(x) swab32(x)
#define cpu_to_le64(x) swab64(x)
#define cpu_to_be16(x) ((uint16_t)(x))
#define cpu_to_be32(x) ((uint32_t)(x))
#define cpu_to_be64(x) ((uint64_t)(x))

#define le16_to_cpu(x) swab16(x)
#define le32_to_cpu(x) swab32(x)
#define le64_to_cpu(x) swab64(x)
#define be16_to_cpu(x) ((uint16_t)(x))
#define be32_to_cpu(x) ((uint32_t)(x))
#define be64_to_cpu(x) ((uint64_t)(x))

#else /* !WORDS_BIGENDIAN */

#define cpu_to_le16(x) ((uint16_t)(x))
#define cpu_to_le32(x) ((uint32_t)(x))
#define cpu_to_le64(x) ((uint64_t)(x))
#define cpu_to_be16(x) swab16(x)
#define cpu_to_be32(x) swab32(x)
#define cpu_to_be64(x) swab64(x)

#define le16_to_cpu(x) ((uint16_t)(x))
#define le32_to_cpu(x) ((uint32_t)(x))
#define le64_to_cpu(x) ((uint64_t)(x))
#define be16_to_cpu(x) swab16(x)
#define be32_to_cpu(x) swab32(x)
#define be64_to_cpu(x) swab64(x)

#endif /* WORDS_BIGENDIAN */

#endif /* BITOPS_H */

