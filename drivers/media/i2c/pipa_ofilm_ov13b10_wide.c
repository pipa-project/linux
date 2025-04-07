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

#define to_pipa_ofilm_ov13b10_wide(_sd) container_of(_sd, struct pipa_ofilm_ov13b10_wide, sd)

struct pipa_ofilm_ov13b10_wide_reg {
    u16 address;
    u32 val;
};

struct pipa_ofilm_ov13b10_wide_reg_list {
    u32 num_of_regs;
    const struct pipa_ofilm_ov13b10_wide_reg *regs;
};

struct pipa_ofilm_ov13b10_wide_mode {
    u32 width;
    u32 height;
    u32 hts;
    u32 vts;
    s64 link_freq;
    u32 lane_count;
    u32 depth;
    const struct pipa_ofilm_ov13b10_wide_reg_list reg_list;
    u32 mbus_code;
};

static const struct pipa_ofilm_ov13b10_wide_reg pipa_ofilm_ov13b10_wide_regs[] = {
	{0x0103, 0x0001},
	{0x0102, 0x0001},
	{0x0303, 0x0004},
	{0x0305, 0x00af},
	{0x0321, 0x0000},
	{0x0323, 0x0002},
	{0x0324, 0x0001},
	{0x0325, 0x0019},
	{0x0326, 0x0081},
	{0x0327, 0x0004},
	{0x3011, 0x007c},
	{0x3012, 0x0007},
	{0x3013, 0x0032},
	{0x3107, 0x0023},
	{0x3501, 0x000c},
	{0x3502, 0x0010},
	{0x3504, 0x0008},
	{0x3508, 0x0007},
	{0x3509, 0x00c0},
	{0x3600, 0x0016},
	{0x3601, 0x0054},
	{0x3612, 0x004e},
	{0x3620, 0x0000},
	{0x3621, 0x0068},
	{0x3622, 0x0066},
	{0x3623, 0x0003},
	{0x3662, 0x0092},
	{0x3666, 0x00bb},
	{0x3667, 0x0044},
	{0x366e, 0x00ff},
	{0x366f, 0x00f3},
	{0x3675, 0x0044},
	{0x3676, 0x0000},
	{0x367f, 0x00e9},
	{0x3681, 0x0032},
	{0x3682, 0x001f},
	{0x3683, 0x000b},
	{0x3684, 0x000b},
	{0x3704, 0x000f},
	{0x3706, 0x0040},
	{0x3708, 0x003b},
	{0x3709, 0x0072},
	{0x370b, 0x00a2},
	{0x3714, 0x0024},
	{0x371a, 0x003e},
	{0x3725, 0x0042},
	{0x3739, 0x0012},
	{0x3767, 0x0000},
	{0x377a, 0x000d},
	{0x3789, 0x0018},
	{0x3790, 0x0040},
	{0x3791, 0x00a2},
	{0x37c2, 0x0004},
	{0x37c3, 0x00f1},
	{0x37d9, 0x000c},
	{0x37da, 0x0002},
	{0x37dc, 0x0002},
	{0x37e1, 0x0004},
	{0x37e2, 0x000a},
	{0x37e4, 0x0004},
	{0x3800, 0x0000},
	{0x3801, 0x0000},
	{0x3802, 0x0000},
	{0x3803, 0x0008},
	{0x3804, 0x0010},
	{0x3805, 0x008f},
	{0x3806, 0x000c},
	{0x3807, 0x0047},
	{0x3808, 0x0010},
	{0x3809, 0x0070},
	{0x380a, 0x000c},
	{0x380b, 0x0030},
	{0x380c, 0x0004},
	{0x380d, 0x0098},
	{0x380e, 0x000c},
	{0x380f, 0x007c},
	{0x3811, 0x000f},
	{0x3813, 0x0008},
	{0x3814, 0x0001},
	{0x3815, 0x0001},
	{0x3816, 0x0001},
	{0x3817, 0x0001},
	{0x381f, 0x0008},
	{0x3820, 0x0088},
	{0x3821, 0x0000},
	{0x3822, 0x0014},
	{0x3823, 0x0018},
	{0x3827, 0x0001},
	{0x382e, 0x00e6},
	{0x3c80, 0x0000},
	{0x3c87, 0x0001},
	{0x3c8c, 0x0019},
	{0x3c8d, 0x001c},
	{0x3ca0, 0x0000},
	{0x3ca1, 0x0000},
	{0x3ca2, 0x0000},
	{0x3ca3, 0x0000},
	{0x3ca4, 0x0050},
	{0x3ca5, 0x0011},
	{0x3ca6, 0x0001},
	{0x3ca7, 0x0000},
	{0x3ca8, 0x0000},
	{0x4008, 0x0002},
	{0x4009, 0x000f},
	{0x400a, 0x0001},
	{0x400b, 0x0019},
	{0x4011, 0x0021},
	{0x4017, 0x0008},
	{0x4019, 0x0004},
	{0x401a, 0x0058},
	{0x4032, 0x001e},
	{0x4050, 0x0002},
	{0x4051, 0x0009},
	{0x405e, 0x0000},
	{0x4066, 0x0002},
	{0x4501, 0x0000},
	{0x4502, 0x0010},
	{0x4505, 0x0000},
	{0x4800, 0x0064},
	{0x481b, 0x003e},
	{0x481f, 0x0030},
	{0x4825, 0x0034},
	{0x4837, 0x000e},
	{0x484b, 0x0001},
	{0x4883, 0x0002},
	{0x5000, 0x00ff},
	{0x5001, 0x000f},
	{0x5045, 0x0020},
	{0x5046, 0x0020},
	{0x5047, 0x00a4},
	{0x5048, 0x0020},
	{0x5049, 0x00a4},
};

static const struct pipa_ofilm_ov13b10_wide_reg pipa_ofilm_ov13b10_wide_4208x3120_4lane_regs[] = {
	{0x3501, 0x000c},
	{0x3662, 0x0092},
	{0x3714, 0x0024},
	{0x3739, 0x0012},
	{0x37c2, 0x0004},
	{0x37d9, 0x000c},
	{0x37e2, 0x000a},
	{0x37e4, 0x0004},
	{0x3800, 0x0000},
	{0x3801, 0x0000},
	{0x3802, 0x0000},
	{0x3803, 0x0008},
	{0x3804, 0x0010},
	{0x3805, 0x008f},
	{0x3806, 0x000c},
	{0x3807, 0x0047},
	{0x3808, 0x0010},
	{0x3809, 0x0070},
	{0x380a, 0x000c},
	{0x380b, 0x0030},
	{0x380c, 0x0004},
	{0x380d, 0x0098},
	{0x380e, 0x000c},
	{0x380f, 0x0070},
	{0x3811, 0x000f},
	{0x3813, 0x0008},
	{0x3814, 0x0001},
	{0x3815, 0x0001},
	{0x3816, 0x0001},
	{0x3817, 0x0001},
	{0x381f, 0x0008},
	{0x3820, 0x0088},
	{0x3821, 0x0000},
	{0x3c8c, 0x0019},
	{0x4008, 0x0002},
	{0x4009, 0x000f},
	{0x4050, 0x0002},
	{0x4051, 0x0009},
	{0x4501, 0x0000},
	{0x4502, 0x0010},
	{0x4505, 0x0000},
	{0x5000, 0x00ff},
	{0x5001, 0x000f},
	{0x0327, 0x0005},
	{0x3621, 0x0028},
	{0x3622, 0x00e6},
	{0x3623, 0x0000},
	{0x3f02, 0x002a},
	{0x3f03, 0x0010},
};

static const struct pipa_ofilm_ov13b10_wide_reg pipa_ofilm_ov13b10_wide_4208x2368_4lane_regs[] = {
	{0x3501, 0x000c},
	{0x3662, 0x0092},
	{0x3714, 0x0024},
	{0x3739, 0x0012},
	{0x37c2, 0x0004},
	{0x37d9, 0x000c},
	{0x37e2, 0x000a},
	{0x37e4, 0x0004},
	{0x3800, 0x0000},
	{0x3801, 0x0000},
	{0x3802, 0x0001},
	{0x3803, 0x0078},
	{0x3804, 0x0010},
	{0x3805, 0x008f},
	{0x3806, 0x000a},
	{0x3807, 0x00d7},
	{0x3808, 0x0010},
	{0x3809, 0x0070},
	{0x380a, 0x0009},
	{0x380b, 0x0040},
	{0x380c, 0x0004},
	{0x380d, 0x0098},
	{0x380e, 0x000c},
	{0x380f, 0x0070},
	{0x3811, 0x000f},
	{0x3813, 0x0010},
	{0x3814, 0x0001},
	{0x3815, 0x0001},
	{0x3816, 0x0001},
	{0x3817, 0x0001},
	{0x381f, 0x0008},
	{0x3820, 0x0088},
	{0x3821, 0x0000},
	{0x3c8c, 0x0019},
	{0x4008, 0x0002},
	{0x4009, 0x000f},
	{0x4050, 0x0002},
	{0x4051, 0x0009},
	{0x4501, 0x0000},
	{0x4502, 0x0010},
	{0x4505, 0x0000},
	{0x5000, 0x00ff},
	{0x5001, 0x000f},
	{0x0327, 0x0005},
	{0x3621, 0x0028},
	{0x3622, 0x00e6},
	{0x3623, 0x0000},
	{0x3f02, 0x002a},
	{0x3f03, 0x0010},
};

static const struct pipa_ofilm_ov13b10_wide_reg pipa_ofilm_ov13b10_wide_2104x1560_4lane_regs[] = {
	{0x3501, 0x0006},
	{0x3662, 0x0088},
	{0x3714, 0x0028},
	{0x3739, 0x0010},
	{0x37c2, 0x0014},
	{0x37d9, 0x0006},
	{0x37e2, 0x000c},
	{0x37e4, 0x0000},
	{0x3800, 0x0000},
	{0x3801, 0x0000},
	{0x3802, 0x0000},
	{0x3803, 0x0008},
	{0x3804, 0x0010},
	{0x3805, 0x008f},
	{0x3806, 0x000c},
	{0x3807, 0x0047},
	{0x3808, 0x0008},
	{0x3809, 0x0038},
	{0x380a, 0x0006},
	{0x380b, 0x0018},
	{0x380c, 0x0004},
	{0x380d, 0x0098},
	{0x380e, 0x0006},
	{0x380f, 0x0038},
	{0x3811, 0x0007},
	{0x3813, 0x0004},
	{0x3814, 0x0003},
	{0x3815, 0x0001},
	{0x3816, 0x0003},
	{0x3817, 0x0001},
	{0x381f, 0x0008},
	{0x3820, 0x008b},
	{0x3821, 0x0000},
	{0x3c8c, 0x0018},
	{0x4008, 0x0000},
	{0x4009, 0x0005},
	{0x4050, 0x0000},
	{0x4051, 0x0005},
	{0x4501, 0x0008},
	{0x4502, 0x0010},
	{0x4505, 0x0004},
	{0x5000, 0x00fd},
	{0x5001, 0x000d},
	{0x0327, 0x0004},
	{0x3621, 0x0068},
	{0x3622, 0x0066},
	{0x3623, 0x0003},
	{0x3f02, 0x000f},
	{0x3f03, 0x0000},
};

static struct pipa_ofilm_ov13b10_wide_mode pipa_ofilm_ov13b10_wide_modes[] = {
    {
        .width = 4208,
        .height = 3120,
        .hts = 1176,
        .vts = 3184,
        .link_freq = 720000000,
        .lane_count = 4,
        .depth = 10,
        .reg_list = {
            .num_of_regs = ARRAY_SIZE(pipa_ofilm_ov13b10_wide_4208x3120_4lane_regs),
            .regs = pipa_ofilm_ov13b10_wide_4208x3120_4lane_regs,
        },
        .mbus_code = MEDIA_BUS_FMT_SBGGR10_1X10,
    },
    {
        .width = 4208,
        .height = 2368,
        .hts = 1176,
        .vts = 3184,
        .link_freq = 480000000,
        .lane_count = 4,
        .depth = 10,
        .reg_list = {
            .num_of_regs = ARRAY_SIZE(pipa_ofilm_ov13b10_wide_4208x2368_4lane_regs),
            .regs = pipa_ofilm_ov13b10_wide_4208x2368_4lane_regs,
        },
        .mbus_code = MEDIA_BUS_FMT_SBGGR10_1X10,
    },
    {
        .width = 2104,
        .height = 1560,
        .hts = 1176,
        .vts = 1592,
        .link_freq = 360000000,
        .lane_count = 4,
        .depth = 10,
        .reg_list = {
            .num_of_regs = ARRAY_SIZE(pipa_ofilm_ov13b10_wide_2104x1560_4lane_regs),
            .regs = pipa_ofilm_ov13b10_wide_2104x1560_4lane_regs,
        },
        .mbus_code = MEDIA_BUS_FMT_SBGGR10_1X10,
    },
};

static const char * const pipa_ofilm_ov13b10_wide_supply_names[] = {
	"vana",
	"vdig",
	"vio",
};

struct pipa_ofilm_ov13b10_wide {
	struct clk *xvclk;
	struct v4l2_subdev sd;
	struct media_pad pad;
	struct v4l2_ctrl_handler ctrl_handler;
	struct v4l2_ctrl *pixel_rate;
	struct v4l2_ctrl *hblank;
	struct v4l2_ctrl *vblank;
	struct v4l2_ctrl *exposure;
	struct pipa_ofilm_ov13b10_wide_mode *cur_mode;
	struct regulator_bulk_data supplies[ARRAY_SIZE(pipa_ofilm_ov13b10_wide_supply_names)];
};

static int pipa_ofilm_ov13b10_wide_write(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide, u16 reg, u16 len, u32 val)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_ofilm_ov13b10_wide->sd);
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

static int pipa_ofilm_ov13b10_wide_write_reg_list(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide, const struct pipa_ofilm_ov13b10_wide_reg_list *reg_list)
{
    int ret = 0;

	for (unsigned int i = 0; i < reg_list->num_of_regs; i++)
	    ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, reg_list->regs[i].address, 1, reg_list->regs[i].val);

    return ret;
}

static int pipa_ofilm_ov13b10_wide_read(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide, u16 reg, u16 len, u32 *val)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_ofilm_ov13b10_wide->sd);
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

static int pipa_ofilm_ov13b10_wide_start_stream(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide,
			       struct v4l2_subdev_state *state)
{
	int ret;
	const struct pipa_ofilm_ov13b10_wide_reg_list regs = {
		.num_of_regs = ARRAY_SIZE(pipa_ofilm_ov13b10_wide_regs),
		.regs = pipa_ofilm_ov13b10_wide_regs,
	};

    ret = pipa_ofilm_ov13b10_wide_write_reg_list(pipa_ofilm_ov13b10_wide, &regs);
	if (ret)
		return ret;

	ret = pipa_ofilm_ov13b10_wide_write_reg_list(pipa_ofilm_ov13b10_wide, &pipa_ofilm_ov13b10_wide->cur_mode->reg_list);
	if (ret)
		return ret;

	ret = __v4l2_ctrl_handler_setup(&pipa_ofilm_ov13b10_wide->ctrl_handler);
	if (ret)
		return ret;

    ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x0100, 1, 0x01);
    if (ret)
		return ret;

    return 0;
}

static int pipa_ofilm_ov13b10_wide_stop_stream(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide)
{
    int ret;

    ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x0100, 1, 0x00);
    if (ret)
		return ret;

    return 0;
}

static int pipa_ofilm_ov13b10_wide_s_stream(struct v4l2_subdev *sd, int on)
{
	struct i2c_client *client = v4l2_get_subdevdata(sd);
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);
	struct v4l2_subdev_state *state;
	int ret = 0;

	state = v4l2_subdev_lock_and_get_active_state(sd);

	if (on) {
		ret = pm_runtime_resume_and_get(&client->dev);
		if (ret < 0)
			goto unlock_and_return;

		ret = pipa_ofilm_ov13b10_wide_start_stream(pipa_ofilm_ov13b10_wide, state);
		if (ret) {
			dev_err(&client->dev, "Failed to start streaming\n");
			pm_runtime_put_sync(&client->dev);
			goto unlock_and_return;
		}
	} else {
		pipa_ofilm_ov13b10_wide_stop_stream(pipa_ofilm_ov13b10_wide);
		pm_runtime_mark_last_busy(&client->dev);
		pm_runtime_put_autosuspend(&client->dev);
	}

unlock_and_return:
	v4l2_subdev_unlock_state(state);

	return ret;
}

static int pipa_ofilm_ov13b10_wide_set_fmt(struct v4l2_subdev *sd,
			  struct v4l2_subdev_state *state,
			  struct v4l2_subdev_format *fmt)
{
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);
	struct pipa_ofilm_ov13b10_wide_mode *mode;
	u64 pixel_rate;
	u32 v_blank;
	u32 h_blank;

	mode = v4l2_find_nearest_size(pipa_ofilm_ov13b10_wide_modes, ARRAY_SIZE(pipa_ofilm_ov13b10_wide_modes),
				      width, height, fmt->format.width,
				      fmt->format.height);

	fmt->format.code = mode->mbus_code;
	fmt->format.width = mode->width;
	fmt->format.height = mode->height;
	fmt->format.field = V4L2_FIELD_NONE;

	if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
		*v4l2_subdev_state_get_format(state, 0) =  fmt->format;
    } else {
        pipa_ofilm_ov13b10_wide->cur_mode = mode;
		pixel_rate = mode->link_freq * 2 * mode->lane_count / mode->depth;
		__v4l2_ctrl_s_ctrl_int64(pipa_ofilm_ov13b10_wide->pixel_rate, pixel_rate);
		/* Update limits and set FPS to default */
		v_blank = mode->vts - mode->height;
		__v4l2_ctrl_modify_range(pipa_ofilm_ov13b10_wide->vblank, v_blank,
					 0xffff - mode->height,
					 1, v_blank);
		__v4l2_ctrl_s_ctrl(pipa_ofilm_ov13b10_wide->vblank, v_blank);
		h_blank = mode->hts - mode->width;
		__v4l2_ctrl_modify_range(pipa_ofilm_ov13b10_wide->hblank, h_blank,
					 h_blank, 1, h_blank);
    }

	return 0;
}

static int pipa_ofilm_ov13b10_wide_get_selection(struct v4l2_subdev *sd,
			  struct v4l2_subdev_state *sd_state,
			  struct v4l2_subdev_selection *sel)
{
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);

	switch (sel->target) {
	case V4L2_SEL_TGT_CROP:
		sel->r = *v4l2_subdev_state_get_crop(sd_state, sel->pad);
		return 0;

	case V4L2_SEL_TGT_NATIVE_SIZE:
		sel->r.top = 0;
		sel->r.left = 0;
		sel->r.width = pipa_ofilm_ov13b10_wide->cur_mode->width;
		sel->r.height = pipa_ofilm_ov13b10_wide->cur_mode->height;
		return 0;

	case V4L2_SEL_TGT_CROP_DEFAULT:
	case V4L2_SEL_TGT_CROP_BOUNDS:
		sel->r.top = 0;
		sel->r.left = 0;
		sel->r.width = pipa_ofilm_ov13b10_wide->cur_mode->width;
		sel->r.height = pipa_ofilm_ov13b10_wide->cur_mode->height;
		return 0;
	}

	return -EINVAL;
}

static int pipa_ofilm_ov13b10_wide_enum_frame_sizes(struct v4l2_subdev *sd,
				   struct v4l2_subdev_state *state,
				   struct v4l2_subdev_frame_size_enum *fse)
{
	if (fse->index >= ARRAY_SIZE(pipa_ofilm_ov13b10_wide_modes))
		return -EINVAL;

	if (fse->code != pipa_ofilm_ov13b10_wide_modes[fse->index].mbus_code)
		return -EINVAL;

	fse->min_width  = pipa_ofilm_ov13b10_wide_modes[fse->index].width;
	fse->max_width  = pipa_ofilm_ov13b10_wide_modes[fse->index].width;
	fse->max_height = pipa_ofilm_ov13b10_wide_modes[fse->index].height;
	fse->min_height = pipa_ofilm_ov13b10_wide_modes[fse->index].height;

	return 0;
}

static int pipa_ofilm_ov13b10_wide_enum_mbus_code(struct v4l2_subdev *sd,
				 struct v4l2_subdev_state *state,
				 struct v4l2_subdev_mbus_code_enum *code)
{
    struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);

    if (code->index != 0)
		return -EINVAL;

    code->code = pipa_ofilm_ov13b10_wide->cur_mode->mbus_code;

    return 0;
}

static int pipa_ofilm_ov13b10_wide_init_state(struct v4l2_subdev *sd,
			     struct v4l2_subdev_state *sd_state)
{
    struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);
	struct v4l2_subdev_format fmt = {
		.which = V4L2_SUBDEV_FORMAT_TRY,
		.format = {
			.width = pipa_ofilm_ov13b10_wide->cur_mode->width,
			.height = pipa_ofilm_ov13b10_wide->cur_mode->height,
		},
	};

	pipa_ofilm_ov13b10_wide_set_fmt(sd, sd_state, &fmt);

	return 0;
}

static int pipa_ofilm_ov13b10_wide_set_ctrl(struct v4l2_ctrl *ctrl)
{
    struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = container_of(ctrl->handler,
					     struct pipa_ofilm_ov13b10_wide, ctrl_handler);
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_ofilm_ov13b10_wide->sd);
	struct v4l2_mbus_framefmt *format;
	struct v4l2_subdev_state *state;
	u32 exposure_max;
	int ret;

	state = v4l2_subdev_get_locked_active_state(&pipa_ofilm_ov13b10_wide->sd);
	format = v4l2_subdev_state_get_format(state, 0);

	/* Propagate change of current control to all related controls */
	if (ctrl->id == V4L2_CID_VBLANK) {
		/* Update max exposure while meeting expected vblanking */
		exposure_max = pipa_ofilm_ov13b10_wide->cur_mode->height + ctrl->val - 2;
		dev_info(&client->dev, "%s V4L2_CID_VBLANK new exposure_max: %d\n",
			 __func__, exposure_max);
		__v4l2_ctrl_modify_range(pipa_ofilm_ov13b10_wide->exposure,
					 pipa_ofilm_ov13b10_wide->exposure->minimum,
					 exposure_max, pipa_ofilm_ov13b10_wide->exposure->step,
					 exposure_max);
	}

	if (!pm_runtime_get_if_in_use(&client->dev))
		return 0;

	switch (ctrl->id) {
	case V4L2_CID_EXPOSURE:
		dev_info(&client->dev, "%s V4L2_CID_EXPOSURE: %d\n",
			 __func__, ctrl->val);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0x00);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3500, 2, ctrl->val);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0x10);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0xa0);
		break;
	case V4L2_CID_ANALOGUE_GAIN:
		dev_info(&client->dev, "%s V4L2_CID_ANALOGUE_GAIN: %d\n",
			 __func__, ctrl->val);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0x00);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3508, 2, ctrl->val);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0x10);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0xa0);
        break;
    case V4L2_CID_VBLANK:
		dev_info(&client->dev, "%s V4L2_CID_VBLANK: %d\n",
			 __func__, ctrl->val);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0x00);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x380e, 2, pipa_ofilm_ov13b10_wide->cur_mode->height + ctrl->val);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0x10);
		ret = pipa_ofilm_ov13b10_wide_write(pipa_ofilm_ov13b10_wide, 0x3208, 1, 0xa0);
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

static const struct v4l2_subdev_core_ops pipa_ofilm_ov13b10_wide_core_ops = { };

static const struct v4l2_subdev_video_ops pipa_ofilm_ov13b10_wide_video_ops = {
	.s_stream = pipa_ofilm_ov13b10_wide_s_stream,
};

static const struct v4l2_subdev_pad_ops pipa_ofilm_ov13b10_wide_pad_ops = {
	.enum_mbus_code = pipa_ofilm_ov13b10_wide_enum_mbus_code,
	.enum_frame_size = pipa_ofilm_ov13b10_wide_enum_frame_sizes,
	.get_fmt = v4l2_subdev_get_fmt,
	.set_fmt = pipa_ofilm_ov13b10_wide_set_fmt,
	.get_selection = pipa_ofilm_ov13b10_wide_get_selection,
};

static const struct v4l2_subdev_ops pipa_ofilm_ov13b10_wide_subdev_ops = {
	.core	= &pipa_ofilm_ov13b10_wide_core_ops,
	.video	= &pipa_ofilm_ov13b10_wide_video_ops,
	.pad	= &pipa_ofilm_ov13b10_wide_pad_ops,
};

static const struct v4l2_subdev_internal_ops pipa_ofilm_ov13b10_wide_internal_ops = {
	.init_state = pipa_ofilm_ov13b10_wide_init_state,
};

static const struct v4l2_ctrl_ops pipa_ofilm_ov13b10_wide_ctrl_ops = {
	.s_ctrl = pipa_ofilm_ov13b10_wide_set_ctrl,
};

static int pipa_ofilm_ov13b10_wide_power_on(struct device *dev)
{
	struct v4l2_subdev *sd = dev_get_drvdata(dev);
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);
	int ret;
	usleep_range(1000, 2000);

    ret = regulator_bulk_enable(ARRAY_SIZE(pipa_ofilm_ov13b10_wide_supply_names),
				    pipa_ofilm_ov13b10_wide->supplies);
    if (ret) {
		dev_err(dev, "failed to enable regulators\n");
		return ret;
	}
	usleep_range(1000, 2000);
	usleep_range(5000, 6000);

    ret = clk_prepare_enable(pipa_ofilm_ov13b10_wide->xvclk);
    if (ret) {
        dev_err(dev, "Failed to enable xvclk\n");
		goto disable_regulator;
	}
	usleep_range(5000, 6000);

	return 0;

disable_regulator:
    regulator_bulk_disable(ARRAY_SIZE(pipa_ofilm_ov13b10_wide_supply_names),
			       pipa_ofilm_ov13b10_wide->supplies);
	return ret;
};

static int pipa_ofilm_ov13b10_wide_power_off(struct device *dev)
{
	struct v4l2_subdev *sd = dev_get_drvdata(dev);
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);

	clk_disable_unprepare(pipa_ofilm_ov13b10_wide->xvclk);
	usleep_range(1000, 2000);
	usleep_range(1000, 2000);

    regulator_bulk_disable(ARRAY_SIZE(pipa_ofilm_ov13b10_wide_supply_names),
    			       pipa_ofilm_ov13b10_wide->supplies);
    return 0;
};

static int pipa_ofilm_ov13b10_wide_init_ctrls(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_ofilm_ov13b10_wide->sd);
	struct v4l2_ctrl_handler *handler = &pipa_ofilm_ov13b10_wide->ctrl_handler;
	struct v4l2_fwnode_device_properties props;
	struct v4l2_ctrl *ctrl;
	struct pipa_ofilm_ov13b10_wide_mode *mode = pipa_ofilm_ov13b10_wide->cur_mode;
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
	pipa_ofilm_ov13b10_wide->pixel_rate = v4l2_ctrl_new_std(handler, NULL, V4L2_CID_PIXEL_RATE,
			  0, pixel_rate, 1, pixel_rate);

    h_blank = mode->hts - mode->width;
	pipa_ofilm_ov13b10_wide->hblank = v4l2_ctrl_new_std(handler, NULL, V4L2_CID_HBLANK,
					   h_blank, h_blank, 1, h_blank);
	if (pipa_ofilm_ov13b10_wide->hblank)
		pipa_ofilm_ov13b10_wide->hblank->flags |= V4L2_CTRL_FLAG_READ_ONLY;

    v_blank = mode->vts - mode->height;
	pipa_ofilm_ov13b10_wide->vblank = v4l2_ctrl_new_std(handler, &pipa_ofilm_ov13b10_wide_ctrl_ops,
					   V4L2_CID_VBLANK, v_blank,
					   0xffff - mode->height,
					   1, v_blank);

    exposure_max = mode->vts - 4;
	pipa_ofilm_ov13b10_wide->exposure = v4l2_ctrl_new_std(handler, &pipa_ofilm_ov13b10_wide_ctrl_ops,
					     V4L2_CID_EXPOSURE,
					     0,
					     exposure_max, 1,
					     exposure_max);

	v4l2_ctrl_new_std(handler, &pipa_ofilm_ov13b10_wide_ctrl_ops, V4L2_CID_ANALOGUE_GAIN,
			  32, 512, 1, 512); // FIXME

	if (handler->error) {
		ret = handler->error;
		goto err_free_handler;
	}

	ret = v4l2_fwnode_device_parse(&client->dev, &props);
	if (ret)
		goto err_free_handler;

	ret = v4l2_ctrl_new_fwnode_properties(handler, &pipa_ofilm_ov13b10_wide_ctrl_ops,
					      &props);
	if (ret)
		goto err_free_handler;

	pipa_ofilm_ov13b10_wide->sd.ctrl_handler = handler;

	return 0;

err_free_handler:
	dev_err(&client->dev, "Failed to init controls: %d\n", ret);
	v4l2_ctrl_handler_free(handler);

	return ret;
}

static int pipa_ofilm_ov13b10_wide_check_sensor_id(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide)
{
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_ofilm_ov13b10_wide->sd);
	u32 id = 0;
	int ret;

	ret = pipa_ofilm_ov13b10_wide_read(pipa_ofilm_ov13b10_wide, 0x300b, 2, &id);
	if (ret)
	    return ret;

	if (id != 0x0d42) {
		dev_err(&client->dev, "Chip ID mismatch: expected 0x%x, got 0x%x\n", 0x0d42, id);
		return -ENODEV;
	}

	dev_info(&client->dev, "Detected pipa_ofilm_ov13b10_wide sensor\n");
	return 0;
}

static int pipa_ofilm_ov13b10_wide_parse_of(struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide)
{
	struct v4l2_fwnode_endpoint vep = { .bus_type = V4L2_MBUS_CSI2_DPHY };
	struct i2c_client *client = v4l2_get_subdevdata(&pipa_ofilm_ov13b10_wide->sd);
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

	for (unsigned int i = 0; i < ARRAY_SIZE(pipa_ofilm_ov13b10_wide_modes); i++) {
	    struct pipa_ofilm_ov13b10_wide_mode *mode = &pipa_ofilm_ov13b10_wide_modes[i];

	    if (mode->lane_count != vep.bus.mipi_csi2.num_data_lanes)
	        continue;

	    pipa_ofilm_ov13b10_wide->cur_mode = mode;
	    break;
	}

	if (!pipa_ofilm_ov13b10_wide->cur_mode) {
	    dev_err(dev, "Unsupported number of data lanes %u\n",
			vep.bus.mipi_csi2.num_data_lanes);
		return -EINVAL;
	}

	return 0;
}

static int pipa_ofilm_ov13b10_wide_probe(struct i2c_client *client)
{
    struct device *dev = &client->dev;
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide;
	struct v4l2_subdev *sd;
	int ret;

	pipa_ofilm_ov13b10_wide = devm_kzalloc(dev, sizeof(*pipa_ofilm_ov13b10_wide), GFP_KERNEL);
	if (!pipa_ofilm_ov13b10_wide)
		return -ENOMEM;

    pipa_ofilm_ov13b10_wide->xvclk = devm_clk_get(dev, "xvclk");
	if (IS_ERR(pipa_ofilm_ov13b10_wide->xvclk))
		return dev_err_probe(dev, PTR_ERR(pipa_ofilm_ov13b10_wide->xvclk),
				     "Failed to get xvclk\n");

	pipa_ofilm_ov13b10_wide->reset_gpio = devm_gpiod_get(dev, "reset",
						     GPIOD_OUT_LOW);
	if (IS_ERR(pipa_ofilm_ov13b10_wide->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(pipa_ofilm_ov13b10_wide->reset_gpio),
				     "Failed to get reset gpio\n");

	v4l2_i2c_subdev_init(&pipa_ofilm_ov13b10_wide->sd, client, &pipa_ofilm_ov13b10_wide_subdev_ops);
	pipa_ofilm_ov13b10_wide->sd.internal_ops = &pipa_ofilm_ov13b10_wide_internal_ops;

	for (unsigned int i = 0; i < ARRAY_SIZE(pipa_ofilm_ov13b10_wide_supply_names); i++)
	    pipa_ofilm_ov13b10_wide->supplies[i].supply = pipa_ofilm_ov13b10_wide_supply_names[i];

	ret = devm_regulator_bulk_get(&client->dev,
				       ARRAY_SIZE(pipa_ofilm_ov13b10_wide_supply_names),
				       pipa_ofilm_ov13b10_wide->supplies);
	if (ret)
	    return dev_err_probe(dev, ret, "Failed to get regulators\n");

    ret = pipa_ofilm_ov13b10_wide_parse_of(pipa_ofilm_ov13b10_wide);
    if (ret)
        return ret;

    ret = pipa_ofilm_ov13b10_wide_init_ctrls(pipa_ofilm_ov13b10_wide);
    if (ret)
        return ret;

    sd = &pipa_ofilm_ov13b10_wide->sd;
    sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
	pipa_ofilm_ov13b10_wide->pad.flags = MEDIA_PAD_FL_SOURCE;
	sd->entity.function = MEDIA_ENT_F_CAM_SENSOR;
	ret = media_entity_pads_init(&sd->entity, 1, &pipa_ofilm_ov13b10_wide->pad);
	if (ret < 0)
		goto err_free_handler;

    sd->state_lock = pipa_ofilm_ov13b10_wide->ctrl_handler.lock;
	ret = v4l2_subdev_init_finalize(sd);
	if (ret < 0) {
		dev_err(&client->dev, "Subdev initialization error %d\n", ret);
		goto err_clean_entity;
	}

	ret = pipa_ofilm_ov13b10_wide_power_on(dev);
	if (ret)
		goto err_clean_entity;

	pm_runtime_set_active(dev);
	pm_runtime_get_noresume(dev);
	pm_runtime_enable(dev);

	ret = pipa_ofilm_ov13b10_wide_check_sensor_id(pipa_ofilm_ov13b10_wide);
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
	pipa_ofilm_ov13b10_wide_power_off(dev);
err_clean_entity:
	media_entity_cleanup(&sd->entity);
err_free_handler:
	v4l2_ctrl_handler_free(&pipa_ofilm_ov13b10_wide->ctrl_handler);

	return ret;
};

static void pipa_ofilm_ov13b10_wide_remove(struct i2c_client *client)
{
	struct v4l2_subdev *sd = i2c_get_clientdata(client);
	struct pipa_ofilm_ov13b10_wide *pipa_ofilm_ov13b10_wide = to_pipa_ofilm_ov13b10_wide(sd);

	v4l2_async_unregister_subdev(sd);
	media_entity_cleanup(&sd->entity);
	v4l2_ctrl_handler_free(&pipa_ofilm_ov13b10_wide->ctrl_handler);

	pm_runtime_disable(&client->dev);
	if (!pm_runtime_status_suspended(&client->dev))
		pipa_ofilm_ov13b10_wide_power_off(&client->dev);
	pm_runtime_set_suspended(&client->dev);
}

static const struct dev_pm_ops pipa_ofilm_ov13b10_wide_pm_ops = {
	SET_RUNTIME_PM_OPS(pipa_ofilm_ov13b10_wide_power_off, pipa_ofilm_ov13b10_wide_power_on, NULL)
};

static const struct of_device_id pipa_ofilm_ov13b10_wide_of_match[] = {
    { .compatible = "ovti,pipa-ofilm-ov13b10-wide" }, // FIXME
    { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, pipa_ofilm_ov13b10_wide_of_match);

static struct i2c_driver pipa_ofilm_ov13b10_wide_i2c_driver = {
    .driver = {
        .of_match_table = pipa_ofilm_ov13b10_wide_of_match,
        .pm = &pipa_ofilm_ov13b10_wide_pm_ops,
		.name = "pipa_ofilm_ov13b10_wide",
    },
    .probe  = pipa_ofilm_ov13b10_wide_probe,
    .remove = pipa_ofilm_ov13b10_wide_remove,
};

module_i2c_driver(pipa_ofilm_ov13b10_wide_i2c_driver)

MODULE_DESCRIPTION("pipa_ofilm_ov13b10_wide image sensor subdev driver");
MODULE_LICENSE("GPL");
