// Generated camera driver

#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/pm_runtime.h>
#include <linux/regulator/consumer.h>
#include <linux/unaligned.h>

#include <media/v4l2-ctrls.h>
#include <media/v4l2-device.h>
#include <media/v4l2-fwnode.h>

#define to_pipa_aac_hi846w_front(_sd) container_of(_sd, struct pipa_aac_hi846w_front, sd)

struct pipa_aac_hi846w_front_reg {
    u16 address;
    u32 val;
};

struct pipa_aac_hi846w_front_reg_list {
    u32 num_of_regs;
    const struct pipa_aac_hi846w_front_reg *regs;
};

struct pipa_aac_hi846w_front_mode {
    u32 width;
    u32 height;
    u32 hts;
    u32 vts;
    s64 link_freq;
    u32 lane_count;
    u32 depth;
    const struct pipa_aac_hi846w_front_reg_list reg_list;
    u32 mbus_code;
};

static const struct pipa_aac_hi846w_front_reg pipa_aac_hi846w_front_regs[] = {
	{0x0066, 0x0101},
	{0x2000, 0x98e8},
	{0x2002, 0x00ff},
	{0x2004, 0x0006},
	{0x2008, 0x3fff},
	{0x200a, 0xc314},
	{0x2022, 0x4130},
	{0x2034, 0x1292},
	{0x2036, 0xc02e},
	{0x2038, 0x4130},
	{0x206e, 0xf0b2},
	{0x2070, 0xffbf},
	{0x2072, 0x2004},
	{0x2074, 0x43c2},
	{0x2076, 0x82fa},
	{0x2078, 0x12b0},
	{0x207a, 0xcab0},
	{0x207c, 0x42a2},
	{0x207e, 0x7324},
	{0x2080, 0x4130},
	{0x2082, 0x120b},
	{0x2084, 0x425b},
	{0x2086, 0x008c},
	{0x2088, 0x4292},
	{0x208a, 0x7300},
	{0x208c, 0x82f2},
	{0x208e, 0x4292},
	{0x2090, 0x7302},
	{0x2092, 0x82f4},
	{0x2094, 0x1292},
	{0x2096, 0xc006},
	{0x2098, 0x421f},
	{0x209a, 0x0710},
	{0x209c, 0x523f},
	{0x209e, 0x4f82},
	{0x20a0, 0x82e4},
	{0x20a2, 0x93c2},
	{0x20a4, 0x829f},
	{0x20a6, 0x241e},
	{0x20a8, 0x403e},
	{0x20aa, 0xfffe},
	{0x20ac, 0x40b2},
	{0x20ae, 0xec78},
	{0x20b0, 0x82ec},
	{0x20b2, 0x40b2},
	{0x20b4, 0xec78},
	{0x20b6, 0x82ee},
	{0x20b8, 0x40b2},
	{0x20ba, 0xec78},
	{0x20bc, 0x82f0},
	{0x20be, 0x934b},
	{0x20c0, 0x2405},
	{0x20c2, 0x4e0f},
	{0x20c4, 0x503f},
	{0x20c6, 0xffd8},
	{0x20c8, 0x4f82},
	{0x20ca, 0x82ec},
	{0x20cc, 0x907b},
	{0x20ce, 0x0003},
	{0x20d0, 0x200b},
	{0x20d2, 0x421f},
	{0x20d4, 0x82ec},
	{0x20d6, 0x5e0f},
	{0x20d8, 0x4f82},
	{0x20da, 0x82ee},
	{0x20dc, 0x5e0f},
	{0x20de, 0x4f82},
	{0x20e0, 0x82f0},
	{0x20e2, 0x3c02},
	{0x20e4, 0x432e},
	{0x20e6, 0x3fe2},
	{0x20e8, 0x413b},
	{0x20ea, 0x4130},
	{0x20ec, 0x421f},
	{0x20ee, 0x7100},
	{0x20f0, 0x4f0e},
	{0x20f2, 0x503e},
	{0x20f4, 0xffd8},
	{0x20f6, 0x4e82},
	{0x20f8, 0x7a04},
	{0x20fa, 0x421e},
	{0x20fc, 0x82ec},
	{0x20fe, 0x5f0e},
	{0x2100, 0x4e82},
	{0x2102, 0x7a06},
	{0x2104, 0x0b00},
	{0x2106, 0x7304},
	{0x2108, 0x0050},
	{0x210a, 0x40b2},
	{0x210c, 0xd081},
	{0x210e, 0x0b88},
	{0x2110, 0x421e},
	{0x2112, 0x82ee},
	{0x2114, 0x5f0e},
	{0x2116, 0x4e82},
	{0x2118, 0x7a0e},
	{0x211a, 0x521f},
	{0x211c, 0x82f0},
	{0x211e, 0x4f82},
	{0x2120, 0x7a10},
	{0x2122, 0x0b00},
	{0x2124, 0x7304},
	{0x2126, 0x007a},
	{0x2128, 0x40b2},
	{0x212a, 0x0081},
	{0x212c, 0x0b88},
	{0x212e, 0x4392},
	{0x2130, 0x7a0a},
	{0x2132, 0x0800},
	{0x2134, 0x7a0c},
	{0x2136, 0x0b00},
	{0x2138, 0x7304},
	{0x213a, 0x022b},
	{0x213c, 0x40b2},
	{0x213e, 0xd081},
	{0x2140, 0x0b88},
	{0x2142, 0x0b00},
	{0x2144, 0x7304},
	{0x2146, 0x0255},
	{0x2148, 0x40b2},
	{0x214a, 0x0081},
	{0x214c, 0x0b88},
	{0x214e, 0x9382},
	{0x2150, 0x7112},
	{0x2152, 0x2402},
	{0x2154, 0x4392},
	{0x2156, 0x760e},
	{0x2158, 0x4130},
	{0x215a, 0x120b},
	{0x215c, 0x120a},
	{0x215e, 0x4e0a},
	{0x2160, 0x4f0b},
	{0x2162, 0x4c0e},
	{0x2164, 0x4d0f},
	{0x2166, 0x8a0e},
	{0x2168, 0x7b0f},
	{0x216a, 0x2c02},
	{0x216c, 0x4a0c},
	{0x216e, 0x4b0d},
	{0x2170, 0x4c0e},
	{0x2172, 0x4d0f},
	{0x2174, 0x413a},
	{0x2176, 0x413b},
	{0x2178, 0x4130},
	{0x217a, 0x120b},
	{0x217c, 0x120a},
	{0x217e, 0x1209},
	{0x2180, 0x1208},
	{0x2182, 0x1207},
	{0x2184, 0x1206},
	{0x2186, 0x1205},
	{0x2188, 0x42d2},
	{0x218a, 0x82fa},
	{0x218c, 0x82a0},
	{0x218e, 0x403b},
	{0x2190, 0x00c1},
	{0x2192, 0x4b6f},
	{0x2194, 0x4fc2},
	{0x2196, 0x82d4},
	{0x2198, 0x43c2},
	{0x219a, 0x82d5},
	{0x219c, 0x1292},
	{0x219e, 0xc046},
	{0x21a0, 0x4292},
	{0x21a2, 0x7560},
	{0x21a4, 0x82f6},
	{0x21a6, 0x4292},
	{0x21a8, 0x7562},
	{0x21aa, 0x82f8},
	{0x21ac, 0x93cb},
	{0x21ae, 0x0000},
	{0x21b0, 0x2452},
	{0x21b2, 0x4215},
	{0x21b4, 0x7316},
	{0x21b6, 0x4216},
	{0x21b8, 0x7318},
	{0x21ba, 0x421f},
	{0x21bc, 0x0710},
	{0x21be, 0x4f0e},
	{0x21c0, 0x430f},
	{0x21c2, 0x4507},
	{0x21c4, 0x4608},
	{0x21c6, 0x8e07},
	{0x21c8, 0x7f08},
	{0x21ca, 0x421f},
	{0x21cc, 0x82e2},
	{0x21ce, 0x522f},
	{0x21d0, 0x4f09},
	{0x21d2, 0x430a},
	{0x21d4, 0x470d},
	{0x21d6, 0x480e},
	{0x21d8, 0x490b},
	{0x21da, 0x4a0c},
	{0x21dc, 0x870b},
	{0x21de, 0x780c},
	{0x21e0, 0x2c02},
	{0x21e2, 0x490d},
	{0x21e4, 0x4a0e},
	{0x21e6, 0x4d0f},
	{0x21e8, 0x43d2},
	{0x21ea, 0x01b3},
	{0x21ec, 0x4d82},
	{0x21ee, 0x7324},
	{0x21f0, 0x4292},
	{0x21f2, 0x7540},
	{0x21f4, 0x82e8},
	{0x21f6, 0x4292},
	{0x21f8, 0x7542},
	{0x21fa, 0x82ea},
	{0x21fc, 0x434b},
	{0x21fe, 0x823f},
	{0x2200, 0x4f0c},
	{0x2202, 0x430d},
	{0x2204, 0x421e},
	{0x2206, 0x82e8},
	{0x2208, 0x421f},
	{0x220a, 0x82ea},
	{0x220c, 0x5e0c},
	{0x220e, 0x6f0d},
	{0x2210, 0x870c},
	{0x2212, 0x780d},
	{0x2214, 0x2801},
	{0x2216, 0x435b},
	{0x2218, 0x4bc2},
	{0x221a, 0x82fa},
	{0x221c, 0x93c2},
	{0x221e, 0x829a},
	{0x2220, 0x201a},
	{0x2222, 0x93c2},
	{0x2224, 0x82a0},
	{0x2226, 0x2404},
	{0x2228, 0x43b2},
	{0x222a, 0x7540},
	{0x222c, 0x43b2},
	{0x222e, 0x7542},
	{0x2230, 0x93c2},
	{0x2232, 0x82fa},
	{0x2234, 0x2410},
	{0x2236, 0x503e},
	{0x2238, 0x0003},
	{0x223a, 0x630f},
	{0x223c, 0x4e82},
	{0x223e, 0x82e8},
	{0x2240, 0x4f82},
	{0x2242, 0x82ea},
	{0x2244, 0x450c},
	{0x2246, 0x460d},
	{0x2248, 0x8e0c},
	{0x224a, 0x7f0d},
	{0x224c, 0x2c04},
	{0x224e, 0x4582},
	{0x2250, 0x82e8},
	{0x2252, 0x4682},
	{0x2254, 0x82ea},
	{0x2256, 0x4135},
	{0x2258, 0x4136},
	{0x225a, 0x4137},
	{0x225c, 0x4138},
	{0x225e, 0x4139},
	{0x2260, 0x413a},
	{0x2262, 0x413b},
	{0x2264, 0x4130},
	{0x2266, 0x403e},
	{0x2268, 0x00c2},
	{0x226a, 0x421f},
	{0x226c, 0x7314},
	{0x226e, 0xf07f},
	{0x2270, 0x000c},
	{0x2272, 0x5f4f},
	{0x2274, 0x5f4f},
	{0x2276, 0xdfce},
	{0x2278, 0x0000},
	{0x227a, 0xf0fe},
	{0x227c, 0x000f},
	{0x227e, 0x0000},
	{0x2280, 0x4130},
	{0x2282, 0x120b},
	{0x2284, 0x120a},
	{0x2286, 0x1209},
	{0x2288, 0x1208},
	{0x228a, 0x1207},
	{0x228c, 0x1206},
	{0x228e, 0x93c2},
	{0x2290, 0x00c1},
	{0x2292, 0x249f},
	{0x2294, 0x425e},
	{0x2296, 0x00c2},
	{0x2298, 0xc35e},
	{0x229a, 0x425f},
	{0x229c, 0x82a0},
	{0x229e, 0xdf4e},
	{0x22a0, 0x4ec2},
	{0x22a2, 0x00c2},
	{0x22a4, 0x934f},
	{0x22a6, 0x248f},
	{0x22a8, 0x4217},
	{0x22aa, 0x7316},
	{0x22ac, 0x4218},
	{0x22ae, 0x7318},
	{0x22b0, 0x4326},
	{0x22b2, 0xb3e2},
	{0x22b4, 0x00c2},
	{0x22b6, 0x2482},
	{0x22b8, 0x0900},
	{0x22ba, 0x731c},
	{0x22bc, 0x0800},
	{0x22be, 0x731c},
	{0x22c0, 0x421a},
	{0x22c2, 0x7300},
	{0x22c4, 0x421b},
	{0x22c6, 0x7302},
	{0x22c8, 0x421f},
	{0x22ca, 0x7304},
	{0x22cc, 0x9f82},
	{0x22ce, 0x829c},
	{0x22d0, 0x2c02},
	{0x22d2, 0x531a},
	{0x22d4, 0x630b},
	{0x22d6, 0x4a0e},
	{0x22d8, 0x4b0f},
	{0x22da, 0x821e},
	{0x22dc, 0x82f2},
	{0x22de, 0x721f},
	{0x22e0, 0x82f4},
	{0x22e2, 0x2c68},
	{0x22e4, 0x4a09},
	{0x22e6, 0x9339},
	{0x22e8, 0x3460},
	{0x22ea, 0x0b00},
	{0x22ec, 0x7304},
	{0x22ee, 0x0320},
	{0x22f0, 0x421e},
	{0x22f2, 0x7300},
	{0x22f4, 0x421f},
	{0x22f6, 0x7302},
	{0x22f8, 0x531e},
	{0x22fa, 0x630f},
	{0x22fc, 0x4e0c},
	{0x22fe, 0x4f0d},
	{0x2300, 0x821c},
	{0x2302, 0x82f6},
	{0x2304, 0x721d},
	{0x2306, 0x82f8},
	{0x2308, 0x2c0e},
	{0x230a, 0x93b2},
	{0x230c, 0x7560},
	{0x230e, 0x2003},
	{0x2310, 0x93b2},
	{0x2312, 0x7562},
	{0x2314, 0x2408},
	{0x2316, 0x4e82},
	{0x2318, 0x7540},
	{0x231a, 0x4f82},
	{0x231c, 0x7542},
	{0x231e, 0x4e82},
	{0x2320, 0x82f6},
	{0x2322, 0x4f82},
	{0x2324, 0x82f8},
	{0x2326, 0x4e82},
	{0x2328, 0x7316},
	{0x232a, 0x12b0},
	{0x232c, 0xfe66},
	{0x232e, 0x0900},
	{0x2330, 0x730e},
	{0x2332, 0x403f},
	{0x2334, 0x7316},
	{0x2336, 0x4a09},
	{0x2338, 0x8f29},
	{0x233a, 0x478f},
	{0x233c, 0x0000},
	{0x233e, 0x460c},
	{0x2340, 0x430d},
	{0x2342, 0x421e},
	{0x2344, 0x7300},
	{0x2346, 0x421f},
	{0x2348, 0x7302},
	{0x234a, 0x9c0e},
	{0x234c, 0x23f8},
	{0x234e, 0x9d0f},
	{0x2350, 0x23f6},
	{0x2352, 0x0b00},
	{0x2354, 0x7304},
	{0x2356, 0x01f4},
	{0x2358, 0x5036},
	{0x235a, 0x0006},
	{0x235c, 0x460c},
	{0x235e, 0x430d},
	{0x2360, 0x490e},
	{0x2362, 0x4e0f},
	{0x2364, 0x5f0f},
	{0x2366, 0x7f0f},
	{0x2368, 0xe33f},
	{0x236a, 0x521e},
	{0x236c, 0x82e8},
	{0x236e, 0x621f},
	{0x2370, 0x82ea},
	{0x2372, 0x12b0},
	{0x2374, 0xfd5a},
	{0x2376, 0x4e82},
	{0x2378, 0x7540},
	{0x237a, 0x4f82},
	{0x237c, 0x7542},
	{0x237e, 0x403b},
	{0x2380, 0x7316},
	{0x2382, 0x421c},
	{0x2384, 0x82e4},
	{0x2386, 0x430d},
	{0x2388, 0x4b2f},
	{0x238a, 0x590f},
	{0x238c, 0x4f0e},
	{0x238e, 0x430f},
	{0x2390, 0x12b0},
	{0x2392, 0xfd5a},
	{0x2394, 0x4e8b},
	{0x2396, 0x0000},
	{0x2398, 0x4ba2},
	{0x239a, 0x82ce},
	{0x239c, 0x4382},
	{0x239e, 0x82d0},
	{0x23a0, 0x12b0},
	{0x23a2, 0xfe66},
	{0x23a4, 0xd3d2},
	{0x23a6, 0x00c2},
	{0x23a8, 0x3c16},
	{0x23aa, 0x9329},
	{0x23ac, 0x3bc8},
	{0x23ae, 0x4906},
	{0x23b0, 0x5326},
	{0x23b2, 0x3fc5},
	{0x23b4, 0x4a09},
	{0x23b6, 0x8219},
	{0x23b8, 0x82ce},
	{0x23ba, 0x3f95},
	{0x23bc, 0x0800},
	{0x23be, 0x731c},
	{0x23c0, 0x0900},
	{0x23c2, 0x731c},
	{0x23c4, 0x3f7d},
	{0x23c6, 0x0900},
	{0x23c8, 0x730c},
	{0x23ca, 0x0b00},
	{0x23cc, 0x7304},
	{0x23ce, 0x01f4},
	{0x23d0, 0x3fe9},
	{0x23d2, 0x0900},
	{0x23d4, 0x732c},
	{0x23d6, 0x425f},
	{0x23d8, 0x0788},
	{0x23da, 0x4136},
	{0x23dc, 0x4137},
	{0x23de, 0x4138},
	{0x23e0, 0x4139},
	{0x23e2, 0x413a},
	{0x23e4, 0x413b},
	{0x23e6, 0x4130},
	{0x23fe, 0xc056},
	{0x3236, 0xfc22},
	{0x323a, 0xfcec},
	{0x323c, 0xfc82},
	{0x323e, 0xfd7a},
	{0x3246, 0xfe82},
	{0x3248, 0xfc34},
	{0x324e, 0xfc6e},
	{0x326a, 0xc374},
	{0x326c, 0xc37c},
	{0x326e, 0x0000},
	{0x3270, 0xc378},
	{0x32e2, 0x0020},
	{0x0a00, 0x0000},
	{0x0e04, 0x0012},
	{0x002e, 0x1111},
	{0x0032, 0x1111},
	{0x0022, 0x0008},
	{0x0026, 0x0040},
	{0x0028, 0x0017},
	{0x002c, 0x09cf},
	{0x005c, 0x2101},
	{0x0006, 0x09de},
	{0x0008, 0x0ed8},
	{0x000e, 0x0200},
	{0x000c, 0x0022},
	{0x0a22, 0x0000},
	{0x0a24, 0x0000},
	{0x0804, 0x0000},
	{0x0a12, 0x0cc0},
	{0x0a14, 0x0990},
	{0x0710, 0x09b0},
	{0x0074, 0x09d8},
	{0x0076, 0x0000},
	{0x051e, 0x0000},
	{0x0200, 0x0400},
	{0x0a1a, 0x0c00},
	{0x0a0c, 0x0010},
	{0x0a1e, 0x0ccf},
	{0x0402, 0x0110},
	{0x0404, 0x00f4},
	{0x0408, 0x0000},
	{0x0410, 0x008d},
	{0x0412, 0x011a},
	{0x0414, 0x864c},
	{0x021c, 0x0001},
	{0x0c00, 0x9950},
	{0x0c06, 0x0021},
	{0x0c10, 0x0040},
	{0x0c12, 0x0040},
	{0x0c14, 0x0040},
	{0x0c16, 0x0040},
	{0x0a02, 0x0100},
	{0x0a04, 0x014a},
	{0x0418, 0x0000},
	{0x0128, 0x0028},
	{0x012a, 0xffff},
	{0x0120, 0x0046},
	{0x0122, 0x0376},
	{0x012c, 0x0020},
	{0x012e, 0xffff},
	{0x0124, 0x0040},
	{0x0126, 0x0378},
	{0x0746, 0x0050},
	{0x0748, 0x01d5},
	{0x074a, 0x022b},
	{0x074c, 0x03b0},
	{0x0756, 0x043f},
	{0x0758, 0x3f1d},
	{0x0b02, 0xe04d},
	{0x0b10, 0x6821},
	{0x0b12, 0x0120},
	{0x0b14, 0x0001},
	{0x2008, 0x38fd},
	{0x326e, 0x0000},
	{0x0900, 0x0320},
	{0x0902, 0xc31a},
	{0x0914, 0xc109},
	{0x0916, 0x061a},
	{0x0918, 0x0306},
	{0x091a, 0x0b09},
	{0x091c, 0x0c07},
	{0x091e, 0x0a00},
	{0x090c, 0x042a},
	{0x090e, 0x005b},
	{0x0954, 0x0089},
	{0x0956, 0x0000},
	{0x0958, 0xca00},
	{0x095a, 0x9240},
	{0x0040, 0x0200},
	{0x0042, 0x0100},
	{0x0d04, 0x0000},
	{0x0f08, 0x2f04},
	{0x0f30, 0x001f},
	{0x0f36, 0x001f},
	{0x0f04, 0x3a00},
	{0x0f32, 0x0396},
	{0x0f38, 0x0396},
	{0x0f2a, 0x0024},
	{0x006a, 0x0100},
	{0x004c, 0x0100},
	{0x0044, 0x0001},
};

static const struct pipa_aac_hi846w_front_reg pipa_aac_hi846w_front_3264x2448_2lane_regs[] = {
	{0x002e, 0x1111},
	{0x0032, 0x1111},
	{0x0026, 0x0040},
	{0x002c, 0x09cf},
	{0x005c, 0x2101},
	{0x0006, 0x09de},
	{0x0008, 0x0ed8},
	{0x000c, 0x0022},
	{0x0a22, 0x0000},
	{0x0a24, 0x0000},
	{0x0804, 0x0000},
	{0x0a12, 0x0cc0},
	{0x0a14, 0x0990},
	{0x0074, 0x09d8},
	{0x021c, 0x0001},
	{0x0a04, 0x014a},
	{0x0418, 0x0000},
	{0x0128, 0x0028},
	{0x012a, 0xffff},
	{0x0120, 0x0046},
	{0x0122, 0x0376},
	{0x012c, 0x0020},
	{0x012e, 0xffff},
	{0x0124, 0x0040},
	{0x0126, 0x0378},
	{0x0b02, 0xe04d},
	{0x0b10, 0x6821},
	{0x0b12, 0x0120},
	{0x0b14, 0x0001},
	{0x2008, 0x38fd},
	{0x326e, 0x0000},
	{0x0710, 0x09b0},
	{0x0900, 0x0320},
	{0x0902, 0xc31a},
	{0x0914, 0xc109},
	{0x0916, 0x061a},
	{0x0918, 0x0306},
	{0x091a, 0x0b09},
	{0x091c, 0x0c07},
	{0x091e, 0x0a00},
	{0x090c, 0x042a},
	{0x090e, 0x005b},
	{0x0954, 0x0089},
	{0x0956, 0x0000},
	{0x0958, 0xca00},
	{0x095a, 0x9240},
	{0x0f32, 0x0396},
	{0x0f38, 0x0396},
	{0x0f2a, 0x0024},
	{0x004c, 0x0100},
};

static const struct pipa_aac_hi846w_front_reg pipa_aac_hi846w_front_3264x1836_2lane_regs[] = {
	{0x002e, 0x1111},
	{0x0032, 0x1111},
	{0x0026, 0x0172},
	{0x002c, 0x089d},
	{0x005c, 0x2101},
	{0x0006, 0x09dd},
	{0x0008, 0x0ed8},
	{0x000c, 0x0022},
	{0x0a22, 0x0000},
	{0x0a24, 0x0000},
	{0x0804, 0x0000},
	{0x0a12, 0x0cc0},
	{0x0a14, 0x072c},
	{0x0074, 0x09d7},
	{0x021c, 0x0001},
	{0x0a04, 0x014a},
	{0x0418, 0x023e},
	{0x0128, 0x0028},
	{0x012a, 0xffff},
	{0x0120, 0x0046},
	{0x0122, 0x0376},
	{0x012c, 0x0020},
	{0x012e, 0xffff},
	{0x0124, 0x0040},
	{0x0126, 0x0378},
	{0x0b02, 0xe04d},
	{0x0b10, 0x6821},
	{0x0b12, 0x0120},
	{0x0b14, 0x0001},
	{0x2008, 0x38fd},
	{0x326e, 0x0000},
	{0x0710, 0x074c},
	{0x0900, 0x0320},
	{0x0902, 0xc31a},
	{0x0914, 0xc109},
	{0x0916, 0x061a},
	{0x0918, 0x0306},
	{0x091a, 0x0b09},
	{0x091c, 0x0c07},
	{0x091e, 0x0a00},
	{0x090c, 0x042a},
	{0x090e, 0x005b},
	{0x0954, 0x0089},
	{0x0956, 0x0000},
	{0x0958, 0xca00},
	{0x095a, 0x9240},
	{0x0f32, 0x0396},
	{0x0f38, 0x0396},
	{0x0f2a, 0x0024},
	{0x004c, 0x0100},
};

static const struct pipa_aac_hi846w_front_reg pipa_aac_hi846w_front_1920x1080_2lane_regs[] = {
	{0x002e, 0x1111},
	{0x0032, 0x1111},
	{0x0026, 0x02ec},
	{0x002c, 0x0723},
	{0x005c, 0x2101},
	{0x0006, 0x04ef},
	{0x0008, 0x0ed8},
	{0x000c, 0x0022},
	{0x0a22, 0x0000},
	{0x0a24, 0x0000},
	{0x0804, 0x02a0},
	{0x0a12, 0x0780},
	{0x0a14, 0x0438},
	{0x0074, 0x04e9},
	{0x021c, 0x0001},
	{0x0a04, 0x014a},
	{0x0418, 0x04c4},
	{0x0128, 0x0028},
	{0x012a, 0xffff},
	{0x0120, 0x0046},
	{0x0122, 0x0376},
	{0x012c, 0x0020},
	{0x012e, 0xffff},
	{0x0124, 0x0040},
	{0x0126, 0x0378},
	{0x0b02, 0xe04d},
	{0x0b10, 0x6821},
	{0x0b12, 0x0120},
	{0x0b14, 0x0001},
	{0x2008, 0x38fd},
	{0x326e, 0x0000},
	{0x0710, 0x0458},
	{0x0900, 0x0320},
	{0x0902, 0xc31a},
	{0x0914, 0xc109},
	{0x0916, 0x061a},
	{0x0918, 0x0306},
	{0x091a, 0x0b09},
	{0x091c, 0x0c07},
	{0x091e, 0x0a00},
	{0x090c, 0x042a},
	{0x090e, 0x01ff},
	{0x0954, 0x0089},
	{0x0956, 0x0000},
	{0x0958, 0xca00},
	{0x095a, 0x9240},
	{0x0f32, 0x0396},
	{0x0f38, 0x0396},
	{0x0f2a, 0x0024},
	{0x004c, 0x0100},
};

static struct pipa_aac_hi846w_front_mode pipa_aac_hi846w_front_modes[] = {
    {
        .width = 3264,
        .height = 2448,
        .hts = 3800,
        .vts = 2526,
        .link_freq = 720000000,
        .lane_count = 2,
        .depth = 10,
        .reg_list = {
            .num_of_regs = ARRAY_SIZE(pipa_aac_hi846w_front_3264x2448_2lane_regs),
            .regs = pipa_aac_hi846w_front_3264x2448_2lane_regs,
        },
        .mbus_code = MEDIA_BUS_FMT_SGRBG10_1X10,
    },
    {
        .width = 3264,
        .height = 1836,
        .hts = 3800,
        .vts = 2526,
        .link_freq = 480000000,
        .lane_count = 2,
        .depth = 10,
        .reg_list = {
            .num_of_regs = ARRAY_SIZE(pipa_aac_hi846w_front_3264x1836_2lane_regs),
            .regs = pipa_aac_hi846w_front_3264x1836_2lane_regs,
        },
        .mbus_code = MEDIA_BUS_FMT_SGRBG10_1X10,
    },
    {
        .width = 1920,
        .height = 1080,
        .hts = 3800,
        .vts = 1263,
        .link_freq = 360000000,
        .lane_count = 2,
        .depth = 10,
        .reg_list = {
            .num_of_regs = ARRAY_SIZE(pipa_aac_hi846w_front_1920x1080_2lane_regs),
            .regs = pipa_aac_hi846w_front_1920x1080_2lane_regs,
        },
        .mbus_code = MEDIA_BUS_FMT_SGRBG10_1X10,
    },
};

static const char * const pipa_aac_hi846w_front_supply_names[] = {
	"vio",
	"vana",
	"vdig",
};

struct pipa_aac_hi846w_front {
	struct gpio_desc *reset_gpio;
	struct clk *xvclk;
	struct v4l2_subdev sd;
	struct media_pad pad;
	struct v4l2_ctrl_handler ctrl_handler;
	struct v4l2_ctrl *pixel_rate;
	struct v4l2_ctrl *hblank;
	struct v4l2_ctrl *vblank;
	struct v4l2_ctrl *exposure;
	struct pipa_aac_hi846w_front_mode *cur_mode;
	struct regulator_bulk_data supplies[ARRAY_SIZE(pipa_aac_hi846w_front_supply_names)];
};

static int pipa_aac_hi846w_front_write(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front, u16 reg, u16 len, u32 val)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_aac_hi846w_front->sd);
	u8 buf[6];

	if (len > 4)
		return -EINVAL;

	put_unaligned_be16(reg, buf);
	put_unaligned_be32(val << 8 * (4 - len), buf + 2);
	if (i2c_master_send(client, buf, len + 2) != len + 2) {
        dev_err(&client->dev,
                "Cannot write register %u!\n", reg);
		return -EIO;
	}

	return 0;
}

static int pipa_aac_hi846w_front_write_reg_list(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front, const struct pipa_aac_hi846w_front_reg_list *reg_list)
{
    int ret = 0;

	for (unsigned int i = 0; i < reg_list->num_of_regs; i++)
	    ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, reg_list->regs[i].address, 1, reg_list->regs[i].val);

    return ret;
}

static int pipa_aac_hi846w_front_read(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front, u16 reg, u16 len, u32 *val)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_aac_hi846w_front->sd);
	struct i2c_msg msgs[2];
	u8 addr_buf[2];
	u8 data_buf[4] = {0};
	int ret;

	if (len > 4)
		return -EINVAL;

	put_unaligned_be16(reg, addr_buf);
	msgs[0].addr = client->addr;
	msgs[0].flags = 0;
	msgs[0].len = sizeof(addr_buf);
	msgs[0].buf = addr_buf;
	msgs[1].addr = client->addr;
	msgs[1].flags = I2C_M_RD;
	msgs[1].len = len;
	msgs[1].buf = &data_buf[4 - len];

	ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
	if (ret != ARRAY_SIZE(msgs)) {
        dev_err(&client->dev,
                "Cannot read register %u!\n", reg);
		return -EIO;
    }

	*val = get_unaligned_be32(data_buf);

	return 0;
}

static int pipa_aac_hi846w_front_start_stream(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front,
			       struct v4l2_subdev_state *state)
{
	int ret;
	const struct pipa_aac_hi846w_front_reg_list regs = {
		.num_of_regs = ARRAY_SIZE(pipa_aac_hi846w_front_regs),
		.regs = pipa_aac_hi846w_front_regs,
	};

    ret = pipa_aac_hi846w_front_write_reg_list(pipa_aac_hi846w_front, &regs);
	if (ret)
		return ret;

	ret = pipa_aac_hi846w_front_write_reg_list(pipa_aac_hi846w_front, &pipa_aac_hi846w_front->cur_mode->reg_list);
	if (ret)
		return ret;

	ret = __v4l2_ctrl_handler_setup(&pipa_aac_hi846w_front->ctrl_handler);
	if (ret)
		return ret;

    ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0a00, 2, 0x100);
    if (ret)
		return ret;

    return 0;
}

static int pipa_aac_hi846w_front_stop_stream(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front)
{
    int ret;

    ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0a00, 2, 0x00);
    if (ret)
		return ret;

    return 0;
}

static int pipa_aac_hi846w_front_s_stream(struct v4l2_subdev *sd, int on)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);
	struct v4l2_subdev_state *state;
	int ret = 0;

	state = v4l2_subdev_lock_and_get_active_state(sd);

	if (on) {
		ret = pm_runtime_resume_and_get(&client->dev);
		if (ret < 0)
			goto unlock_and_return;

		ret = pipa_aac_hi846w_front_start_stream(pipa_aac_hi846w_front, state);
		if (ret) {
			dev_err(&client->dev, "Failed to start streaming\n");
			pm_runtime_put_sync(&client->dev);
			goto unlock_and_return;
		}
	} else {
		pipa_aac_hi846w_front_stop_stream(pipa_aac_hi846w_front);
		pm_runtime_mark_last_busy(&client->dev);
		pm_runtime_put_autosuspend(&client->dev);
	}

unlock_and_return:
	v4l2_subdev_unlock_state(state);

	return ret;
}

static int pipa_aac_hi846w_front_set_fmt(struct v4l2_subdev *sd,
			  struct v4l2_subdev_state *state,
			  struct v4l2_subdev_format *fmt)
{
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);
	struct pipa_aac_hi846w_front_mode *mode;
	u64 pixel_rate;
	u32 v_blank;
	u32 h_blank;

	mode = v4l2_find_nearest_size(pipa_aac_hi846w_front_modes, ARRAY_SIZE(pipa_aac_hi846w_front_modes),
				      width, height, fmt->format.width,
				      fmt->format.height);

	fmt->format.code = mode->mbus_code;
	fmt->format.width = mode->width;
	fmt->format.height = mode->height;
	fmt->format.field = V4L2_FIELD_NONE;

	if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
		*v4l2_subdev_state_get_format(state, 0) =  fmt->format;
    } else {
        pipa_aac_hi846w_front->cur_mode = mode;
		pixel_rate = mode->link_freq * 2 * mode->lane_count / mode->depth;
		__v4l2_ctrl_s_ctrl_int64(pipa_aac_hi846w_front->pixel_rate, pixel_rate);
		/* Update limits and set FPS to default */
		v_blank = mode->vts - mode->height;
		__v4l2_ctrl_modify_range(pipa_aac_hi846w_front->vblank, v_blank,
					 0xffff - mode->height,
					 1, v_blank);
		__v4l2_ctrl_s_ctrl(pipa_aac_hi846w_front->vblank, v_blank);
		h_blank = mode->hts - mode->width;
		__v4l2_ctrl_modify_range(pipa_aac_hi846w_front->hblank, h_blank,
					 h_blank, 1, h_blank);
    }

	return 0;
}

static int pipa_aac_hi846w_front_get_selection(struct v4l2_subdev *sd,
			  struct v4l2_subdev_state *sd_state,
			  struct v4l2_subdev_selection *sel)
{
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);

	switch (sel->target) {
	case V4L2_SEL_TGT_CROP:
		sel->r = *v4l2_subdev_state_get_crop(sd_state, sel->pad);
		return 0;

	case V4L2_SEL_TGT_NATIVE_SIZE:
		sel->r.top = 0;
		sel->r.left = 0;
		sel->r.width = pipa_aac_hi846w_front->cur_mode->width;
		sel->r.height = pipa_aac_hi846w_front->cur_mode->height;
		return 0;

	case V4L2_SEL_TGT_CROP_DEFAULT:
	case V4L2_SEL_TGT_CROP_BOUNDS:
		sel->r.top = 0;
		sel->r.left = 0;
		sel->r.width = pipa_aac_hi846w_front->cur_mode->width;
		sel->r.height = pipa_aac_hi846w_front->cur_mode->height;
		return 0;
	}

	return -EINVAL;
}

static int pipa_aac_hi846w_front_enum_frame_sizes(struct v4l2_subdev *sd,
				   struct v4l2_subdev_state *state,
				   struct v4l2_subdev_frame_size_enum *fse)
{
	if (fse->index >= ARRAY_SIZE(pipa_aac_hi846w_front_modes))
		return -EINVAL;

	if (fse->code != pipa_aac_hi846w_front_modes[fse->index].mbus_code)
		return -EINVAL;

	fse->min_width  = pipa_aac_hi846w_front_modes[fse->index].width;
	fse->max_width  = pipa_aac_hi846w_front_modes[fse->index].width;
	fse->max_height = pipa_aac_hi846w_front_modes[fse->index].height;
	fse->min_height = pipa_aac_hi846w_front_modes[fse->index].height;

	return 0;
}

static int pipa_aac_hi846w_front_enum_mbus_code(struct v4l2_subdev *sd,
				 struct v4l2_subdev_state *state,
				 struct v4l2_subdev_mbus_code_enum *code)
{
    struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);

    if (code->index != 0)
		return -EINVAL;

    code->code = pipa_aac_hi846w_front->cur_mode->mbus_code;

    return 0;
}

static int pipa_aac_hi846w_front_init_state(struct v4l2_subdev *sd,
			     struct v4l2_subdev_state *sd_state)
{
    struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);
	struct v4l2_subdev_format fmt = {
		.which = V4L2_SUBDEV_FORMAT_TRY,
		.format = {
			.width = pipa_aac_hi846w_front->cur_mode->width,
			.height = pipa_aac_hi846w_front->cur_mode->height,
		},
	};

	pipa_aac_hi846w_front_set_fmt(sd, sd_state, &fmt);

	return 0;
}

static int pipa_aac_hi846w_front_set_ctrl(struct v4l2_ctrl *ctrl)
{
    struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = container_of(ctrl->handler,
					     struct pipa_aac_hi846w_front, ctrl_handler);
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_aac_hi846w_front->sd);
	struct v4l2_mbus_framefmt *format;
	struct v4l2_subdev_state *state;
	u32 exposure_max;
	int ret;

	state = v4l2_subdev_get_locked_active_state(&pipa_aac_hi846w_front->sd);
	format = v4l2_subdev_state_get_format(state, 0);

	/* Propagate change of current control to all related controls */
	if (ctrl->id == V4L2_CID_VBLANK) {
		/* Update max exposure while meeting expected vblanking */
		exposure_max = pipa_aac_hi846w_front->cur_mode->height + ctrl->val - 2;
		dev_info(&client->dev, "%s V4L2_CID_VBLANK new exposure_max: %d\n",
			 __func__, exposure_max);
		__v4l2_ctrl_modify_range(pipa_aac_hi846w_front->exposure,
					 pipa_aac_hi846w_front->exposure->minimum,
					 exposure_max, pipa_aac_hi846w_front->exposure->step,
					 exposure_max);
	}

	if (!pm_runtime_get_if_in_use(&client->dev))
		return 0;

	switch (ctrl->id) {
	case V4L2_CID_EXPOSURE:
		dev_info(&client->dev, "%s V4L2_CID_EXPOSURE: %d\n",
			 __func__, ctrl->val);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0046, 1, 0x01);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0074, 2, ctrl->val);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0046, 1, 0x00);
		break;
	case V4L2_CID_ANALOGUE_GAIN:
		dev_info(&client->dev, "%s V4L2_CID_ANALOGUE_GAIN: %d\n",
			 __func__, ctrl->val);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0046, 1, 0x01);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0076, 2, ctrl->val);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0046, 1, 0x00);
        break;
    case V4L2_CID_VBLANK:
		dev_info(&client->dev, "%s V4L2_CID_VBLANK: %d\n",
			 __func__, ctrl->val);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0046, 1, 0x01);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0006, 2, pipa_aac_hi846w_front->cur_mode->height + ctrl->val);
		ret = pipa_aac_hi846w_front_write(pipa_aac_hi846w_front, 0x0046, 1, 0x00);
        break;
	default:
		ret = -EINVAL;
		dev_warn(&client->dev, "%s Unhandled id: 0x%x\n",
			 __func__, ctrl->id);
		break;
	}

	pm_runtime_put(&client->dev);

	return ret;
}

static const struct v4l2_subdev_core_ops pipa_aac_hi846w_front_core_ops = { };

static const struct v4l2_subdev_video_ops pipa_aac_hi846w_front_video_ops = {
	.s_stream = pipa_aac_hi846w_front_s_stream,
};

static const struct v4l2_subdev_pad_ops pipa_aac_hi846w_front_pad_ops = {
	.enum_mbus_code = pipa_aac_hi846w_front_enum_mbus_code,
	.enum_frame_size = pipa_aac_hi846w_front_enum_frame_sizes,
	.get_fmt = v4l2_subdev_get_fmt,
	.set_fmt = pipa_aac_hi846w_front_set_fmt,
	.get_selection = pipa_aac_hi846w_front_get_selection,
};

static const struct v4l2_subdev_ops pipa_aac_hi846w_front_subdev_ops = {
	.core	= &pipa_aac_hi846w_front_core_ops,
	.video	= &pipa_aac_hi846w_front_video_ops,
	.pad	= &pipa_aac_hi846w_front_pad_ops,
};

static const struct v4l2_subdev_internal_ops pipa_aac_hi846w_front_internal_ops = {
	.init_state = pipa_aac_hi846w_front_init_state,
};

static const struct v4l2_ctrl_ops pipa_aac_hi846w_front_ctrl_ops = {
	.s_ctrl = pipa_aac_hi846w_front_set_ctrl,
};

static int pipa_aac_hi846w_front_power_on(struct device *dev)
{
	struct v4l2_subdev *sd = dev_get_drvdata(dev);
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);
	int ret;
	usleep_range(1000, 2000);

    ret = regulator_bulk_enable(ARRAY_SIZE(pipa_aac_hi846w_front_supply_names),
				    pipa_aac_hi846w_front->supplies);
    if (ret) {
		dev_err(dev, "failed to enable regulators\n");
		return ret;
	}

    ret = clk_prepare_enable(pipa_aac_hi846w_front->xvclk);
    if (ret) {
        dev_err(dev, "Failed to enable xvclk\n");
		goto disable_regulator;
	}
	usleep_range(1000, 2000);
	usleep_range(11000, 12000);

	/* 30us = 2400 cycles at 80Mhz */
	usleep_range(30, 60);
	if (pipa_aac_hi846w_front->reset_gpio)
		gpiod_set_value_cansleep(pipa_aac_hi846w_front->reset_gpio, 0);
	usleep_range(30, 60);

	return 0;

disable_regulator:
    regulator_bulk_disable(ARRAY_SIZE(pipa_aac_hi846w_front_supply_names),
			       pipa_aac_hi846w_front->supplies);
	return ret;
};

static int pipa_aac_hi846w_front_power_off(struct device *dev)
{
	struct v4l2_subdev *sd = dev_get_drvdata(dev);
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);
	usleep_range(1000, 2000);

	if (pipa_aac_hi846w_front->reset_gpio)
		gpiod_set_value_cansleep(pipa_aac_hi846w_front->reset_gpio, 1);

	clk_disable_unprepare(pipa_aac_hi846w_front->xvclk);
	usleep_range(1000, 2000);

    regulator_bulk_disable(ARRAY_SIZE(pipa_aac_hi846w_front_supply_names),
    			       pipa_aac_hi846w_front->supplies);
    return 0;
};

static int pipa_aac_hi846w_front_init_ctrls(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_aac_hi846w_front->sd);
	struct v4l2_ctrl_handler *handler = &pipa_aac_hi846w_front->ctrl_handler;
	struct v4l2_fwnode_device_properties props;
	struct v4l2_ctrl *ctrl;
	struct pipa_aac_hi846w_front_mode *mode = pipa_aac_hi846w_front->cur_mode;
	u64 pixel_rate;
	u32 h_blank;
	u32 v_blank;
	u32 exposure_max;
	int ret;
	static s64 link_freq[] = {
		0
	};
	link_freq[0] = mode->link_freq;

	ret = v4l2_ctrl_handler_init(handler, 5);
	if (ret)
		return ret;

	ctrl = v4l2_ctrl_new_int_menu(handler, NULL, V4L2_CID_LINK_FREQ,
				      ARRAY_SIZE(link_freq) - 1, 0, link_freq);
	if (ctrl)
		ctrl->flags |= V4L2_CTRL_FLAG_READ_ONLY;

	pixel_rate = mode->link_freq * 2 * mode->lane_count / mode->depth;
	pipa_aac_hi846w_front->pixel_rate = v4l2_ctrl_new_std(handler, NULL, V4L2_CID_PIXEL_RATE,
			  0, pixel_rate, 1, pixel_rate);

    h_blank = mode->hts - mode->width;
	pipa_aac_hi846w_front->hblank = v4l2_ctrl_new_std(handler, NULL, V4L2_CID_HBLANK,
					   h_blank, h_blank, 1, h_blank);
	if (pipa_aac_hi846w_front->hblank)
		pipa_aac_hi846w_front->hblank->flags |= V4L2_CTRL_FLAG_READ_ONLY;

    v_blank = mode->vts - mode->height;
	pipa_aac_hi846w_front->vblank = v4l2_ctrl_new_std(handler, &pipa_aac_hi846w_front_ctrl_ops,
					   V4L2_CID_VBLANK, v_blank,
					   0xffff - mode->height,
					   1, v_blank);

    exposure_max = mode->vts - 6;
	pipa_aac_hi846w_front->exposure = v4l2_ctrl_new_std(handler, &pipa_aac_hi846w_front_ctrl_ops,
					     V4L2_CID_EXPOSURE,
					     0,
					     exposure_max, 1,
					     exposure_max);

	v4l2_ctrl_new_std(handler, &pipa_aac_hi846w_front_ctrl_ops, V4L2_CID_ANALOGUE_GAIN,
			  32, 512, 1, 512); // FIXME

	if (handler->error) {
		ret = handler->error;
		goto err_free_handler;
	}

	ret = v4l2_fwnode_device_parse(&client->dev, &props);
	if (ret)
		goto err_free_handler;

	ret = v4l2_ctrl_new_fwnode_properties(handler, &pipa_aac_hi846w_front_ctrl_ops,
					      &props);
	if (ret)
		goto err_free_handler;

	pipa_aac_hi846w_front->sd.ctrl_handler = handler;

	return 0;

err_free_handler:
	dev_err(&client->dev, "Failed to init controls: %d\n", ret);
	v4l2_ctrl_handler_free(handler);

	return ret;
}

static int pipa_aac_hi846w_front_check_sensor_id(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_aac_hi846w_front->sd);
	u32 id = 0;
	int ret;

	ret = pipa_aac_hi846w_front_read(pipa_aac_hi846w_front, 0x0f16, 2, &id);
	if (ret)
	    return ret;

	if (id != 0x4608) {
		dev_err(&client->dev, "Chip ID mismatch: expected 0x%x, got 0x%x\n", 0x4608, id);
		return -ENODEV;
	}

	dev_info(&client->dev, "Detected pipa_aac_hi846w_front sensor\n");
	return 0;
}

static int pipa_aac_hi846w_front_parse_of(struct pipa_aac_hi846w_front *pipa_aac_hi846w_front)
{
	struct v4l2_fwnode_endpoint vep = { .bus_type = V4L2_MBUS_CSI2_DPHY };
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_aac_hi846w_front->sd);
	struct device *dev = &client->dev;
	struct fwnode_handle *endpoint;
	int ret;

	endpoint = fwnode_graph_get_next_endpoint(dev_fwnode(dev), NULL);
	if (!endpoint) {
		dev_err(dev, "Failed to get endpoint\n");
		return -EINVAL;
	}

	ret = v4l2_fwnode_endpoint_parse(endpoint, &vep);
	fwnode_handle_put(endpoint);
	if (ret) {
		dev_err(dev, "Failed to parse endpoint: %d\n", ret);
		return ret;
	}

	for (unsigned int i = 0; i < ARRAY_SIZE(pipa_aac_hi846w_front_modes); i++) {
	    struct pipa_aac_hi846w_front_mode *mode = &pipa_aac_hi846w_front_modes[i];

	    if (mode->lane_count != vep.bus.mipi_csi2.num_data_lanes)
	        continue;

	    pipa_aac_hi846w_front->cur_mode = mode;
	    break;
	}

	if (!pipa_aac_hi846w_front->cur_mode) {
	    dev_err(dev, "Unsupported number of data lanes %u\n",
			vep.bus.mipi_csi2.num_data_lanes);
		return -EINVAL;
	}

	return 0;
}

static int pipa_aac_hi846w_front_probe(struct i2c_client *client)
{
    struct device *dev = &client->dev;
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front;
	struct v4l2_subdev *sd;
	int ret;

	pipa_aac_hi846w_front = devm_kzalloc(dev, sizeof(*pipa_aac_hi846w_front), GFP_KERNEL);
	if (!pipa_aac_hi846w_front)
		return -ENOMEM;

    pipa_aac_hi846w_front->xvclk = devm_clk_get(dev, "xvclk");
	if (IS_ERR(pipa_aac_hi846w_front->xvclk))
		return dev_err_probe(dev, PTR_ERR(pipa_aac_hi846w_front->xvclk),
				     "Failed to get xvclk\n");

	pipa_aac_hi846w_front->reset_gpio = devm_gpiod_get(dev, "reset",
						     GPIOD_OUT_LOW);
	if (IS_ERR(pipa_aac_hi846w_front->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(pipa_aac_hi846w_front->reset_gpio),
				     "Failed to get reset gpio\n");

	v4l2_i2c_subdev_init(&pipa_aac_hi846w_front->sd, client, &pipa_aac_hi846w_front_subdev_ops);
	pipa_aac_hi846w_front->sd.internal_ops = &pipa_aac_hi846w_front_internal_ops;

	for (unsigned int i = 0; i < ARRAY_SIZE(pipa_aac_hi846w_front_supply_names); i++)
	    pipa_aac_hi846w_front->supplies[i].supply = pipa_aac_hi846w_front_supply_names[i];

	ret = devm_regulator_bulk_get(&client->dev,
				       ARRAY_SIZE(pipa_aac_hi846w_front_supply_names),
				       pipa_aac_hi846w_front->supplies);
	if (ret)
	    return dev_err_probe(dev, ret, "Failed to get regulators\n");

    ret = pipa_aac_hi846w_front_parse_of(pipa_aac_hi846w_front);
    if (ret)
        return ret;

    ret = pipa_aac_hi846w_front_init_ctrls(pipa_aac_hi846w_front);
    if (ret)
        return ret;

    sd = &pipa_aac_hi846w_front->sd;
    sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	pipa_aac_hi846w_front->pad.flags = MEDIA_PAD_FL_SOURCE;
	sd->entity.function = MEDIA_ENT_F_CAM_SENSOR;
	ret = media_entity_pads_init(&sd->entity, 1, &pipa_aac_hi846w_front->pad);
	if (ret < 0)
		goto err_free_handler;

    sd->state_lock = pipa_aac_hi846w_front->ctrl_handler.lock;
	ret = v4l2_subdev_init_finalize(sd);
	if (ret < 0) {
		dev_err(&client->dev, "Subdev initialization error %d\n", ret);
		goto err_clean_entity;
	}

	ret = pipa_aac_hi846w_front_power_on(dev);
	if (ret)
		goto err_clean_entity;

	pm_runtime_set_active(dev);
	pm_runtime_get_noresume(dev);
	pm_runtime_enable(dev);

	ret = pipa_aac_hi846w_front_check_sensor_id(pipa_aac_hi846w_front);
	if (ret)
		goto err_power_off;

	pm_runtime_set_autosuspend_delay(dev, 1000);
	pm_runtime_use_autosuspend(dev);

	ret = v4l2_async_register_subdev_sensor(sd);
	if (ret) {
		dev_err(dev, "v4l2 async register subdev failed\n");
		goto err_power_off;
	}

	pm_runtime_mark_last_busy(dev);
	pm_runtime_put_autosuspend(dev);

	return 0;

err_power_off:
	pm_runtime_disable(dev);
	pm_runtime_put_noidle(dev);
	pipa_aac_hi846w_front_power_off(dev);
err_clean_entity:
	media_entity_cleanup(&sd->entity);
err_free_handler:
	v4l2_ctrl_handler_free(&pipa_aac_hi846w_front->ctrl_handler);

	return ret;
};

static void pipa_aac_hi846w_front_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct pipa_aac_hi846w_front *pipa_aac_hi846w_front = to_pipa_aac_hi846w_front(sd);

	v4l2_async_unregister_subdev(sd);
	media_entity_cleanup(&sd->entity);
	v4l2_ctrl_handler_free(&pipa_aac_hi846w_front->ctrl_handler);

	pm_runtime_disable(&client->dev);
	if (!pm_runtime_status_suspended(&client->dev))
		pipa_aac_hi846w_front_power_off(&client->dev);
	pm_runtime_set_suspended(&client->dev);
}

static const struct dev_pm_ops pipa_aac_hi846w_front_pm_ops = {
	SET_RUNTIME_PM_OPS(pipa_aac_hi846w_front_power_off, pipa_aac_hi846w_front_power_on, NULL)
};

static const struct of_device_id pipa_aac_hi846w_front_of_match[] = {
    { .compatible = "hynix,pipa-aac-hi846w-front" }, // FIXME
    { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, pipa_aac_hi846w_front_of_match);

static struct i2c_driver pipa_aac_hi846w_front_i2c_driver = {
    .driver = {
        .of_match_table = pipa_aac_hi846w_front_of_match,
        .pm = &pipa_aac_hi846w_front_pm_ops,
		.name = "pipa_aac_hi846w_front",
    },
    .probe  = pipa_aac_hi846w_front_probe,
    .remove = pipa_aac_hi846w_front_remove,
};

module_i2c_driver(pipa_aac_hi846w_front_i2c_driver)

MODULE_DESCRIPTION("pipa_aac_hi846w_front image sensor subdev driver");
MODULE_LICENSE("GPL");
