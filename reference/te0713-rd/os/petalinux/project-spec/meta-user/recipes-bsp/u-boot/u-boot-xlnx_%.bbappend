FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append = " file://platform-top.h file://bsp.cfg"
SRC_URI += "file://user_2025-02-20-14-02-00.cfg \
            file://user_2025-03-20-15-07-00.cfg \
            file://user_2025-03-20-15-32-00.cfg \
            file://user_2025-03-21-07-59-00.cfg \
            file://user_2025-03-21-08-26-00.cfg \
            file://user_2025-03-27-08-28-00.cfg \
            file://user_2025-03-27-08-49-00.cfg \
            "

