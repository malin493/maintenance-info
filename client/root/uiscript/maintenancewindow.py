BOARD_WIDTH = 283
BOARD_HEIGHT = 63

window = {
	"name" : "MaintenanceWindow",
	"style" : ("float",),

	"x" : SCREEN_WIDTH / 2 - 280 / 2,
	"y" : 0,

	"width" : BOARD_WIDTH,
	"height" : BOARD_HEIGHT,

	"children" :
	(
		{
			"name" : "board",
			"type" : "thinboard",
			"style" : ("attach",),

			"x" : 0,
			"y" : 0,

			"width" : 280,
			"height" : 65,

			"children" :
			(
				{
					"name" : "close",
					"type" : "button",

					"x" : 30,
					"y" : 5,

					"horizontal_align" : "right",

					"default_image" : "d:/ymir work/ui/public/close_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/close_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/close_button_03.sub",
				},
				{
					"name" : "remaining_time",
					"type" : "text",

					"x" : 15,
					"y" : 5,
				},
				{
					"name" : "cause",
					"type" : "text",

					"x" : 15,
					"y" : 25,
				},
				{
					"name" : "duration",
					"type" : "text",

					"x" : 15,
					"y" : 45,
				},
			),
		},
	),
}
