FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://bsp.cfg"
KERNEL_FEATURES:append = " bsp.cfg"
SRC_URI += "file://user_2025-02-20-14-08-00.cfg \
            file://user_2025-03-20-15-35-00.cfg \
            "

