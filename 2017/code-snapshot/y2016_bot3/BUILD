load('/aos/downloader/downloader', 'aos_downloader')

cc_binary(
  name = 'joystick_reader',
  srcs = [
    'joystick_reader.cc',
  ],
  deps = [
    '//aos/common/actions:action_lib',
    '//aos/common/logging',
    '//aos/common/util:log_interval',
    '//aos/common:time',
    '//aos/input:joystick_input',
    '//aos/linux_code:init',
    '//frc971/autonomous:auto_queue',
    '//frc971/control_loops/drivetrain:drivetrain_queue',
    '//frc971/queues:gyro',
    '//y2016_bot3/actors:autonomous_action_lib',
    '//y2016_bot3/control_loops/intake:intake_lib',
    '//y2016_bot3/control_loops/intake:intake_queue',
    '//y2016_bot3/queues:ball_detector',
  ],
)

aos_downloader(
  name = 'download',
  start_srcs = [
    ':joystick_reader',
    ':wpilib_interface',
    '//aos:prime_start_binaries',
    '//y2016_bot3/control_loops/drivetrain:drivetrain',
    '//y2016_bot3/control_loops/intake:intake',
    '//y2016_bot3/actors:autonomous_action',
  ],
  srcs = [
    '//aos:prime_binaries',
  ],
)

aos_downloader(
  name = 'download_stripped',
  start_srcs = [
    ':joystick_reader.stripped',
    ':wpilib_interface.stripped',
    '//aos:prime_start_binaries_stripped',
    '//y2016_bot3/control_loops/drivetrain:drivetrain.stripped',
    '//y2016_bot3/control_loops/intake:intake.stripped',
    '//y2016_bot3/actors:autonomous_action.stripped',
  ],
  srcs = [
    '//aos:prime_binaries_stripped',
  ],
)

cc_binary(
  name = 'wpilib_interface',
  srcs = [
    'wpilib_interface.cc',
  ],
  deps = [
    '//aos/common:stl_mutex',
    '//aos/common/logging',
    '//aos/common:math',
    '//aos/common/controls:control_loop',
    '//aos/common/util:log_interval',
    '//aos/common:time',
    '//aos/common/logging:queue_logging',
    '//aos/common/messages:robot_state',
    '//aos/common/util:phased_loop',
    '//aos/common/util:wrapping_counter',
    '//aos/linux_code:init',
    '//third_party:wpilib',
    '//frc971/control_loops/drivetrain:drivetrain_queue',
    '//frc971/control_loops:queues',
    '//frc971/wpilib:joystick_sender',
    '//frc971/wpilib:loop_output_handler',
    '//frc971/wpilib:buffered_pcm',
    '//frc971/wpilib:gyro_sender',
    '//frc971/wpilib:dma_edge_counting',
    '//frc971/wpilib:interrupt_edge_counting',
    '//frc971/wpilib:wpilib_robot_base',
    '//frc971/wpilib:encoder_and_potentiometer',
    '//frc971/wpilib:logging_queue',
    '//frc971/wpilib:wpilib_interface',
    '//frc971/wpilib:pdp_fetcher',
    '//frc971/wpilib:ADIS16448',
    '//frc971/wpilib:dma',
    '//y2016_bot3/control_loops/drivetrain:polydrivetrain_plants',
    '//y2016_bot3/control_loops/intake:intake_queue',
    '//y2016_bot3/queues:ball_detector',
    '//y2016_bot3/actors:autonomous_action_queue',
    '//y2016_bot3/control_loops/intake:intake_lib',
    '//y2016_bot3/control_loops/drivetrain:drivetrain_base',
  ],
)
