#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>

int main() {
    Display* display = XOpenDisplay(nullptr);
    Window root = DefaultRootWindow(display);

    XWindowAttributes attributes;
    XGetWindowAttributes(display, root, &attributes);

    XImage* img = XGetImage(display, root, 0, 0, attributes.width, attributes.height, AllPlanes, ZPixmap);

    FILE* fp = fopen("screenshot.xwd", "wb");
    XWDFileHeader header;
    header.header_size = sizeof(header);
    header.file_version = XWD_FILE_VERSION;
    header.pixmap_format = XWD_PIXMAP_ZPIXMAP;
    header.pixmap_depth = 24;
    header.pixmap_width = attributes.width;
    header.pixmap_height = attributes.height;
    header.xoffset = 0;
    header.byte_order = MSBFirst;
    header.bitmap_unit = 32;
    header.bitmap_bit_order = MSBFirst;
    header.bitmap_pad = 32;
    header.bits_per_pixel = 32;
    header.bytes_per_line = 0;
    header.visual_class = TrueColor;
    header.red_mask = 0xFF0000;
    header.green_mask = 0x00FF00;
    header.blue_mask = 0x0000FF;
    header.bits_per_rgb = 8;
    fwrite(&header, 1, sizeof(header), fp);
    fwrite(img->data, 1, img->bytes_per_line * attributes.height, fp);
    fclose(fp);

    XDestroyImage(img);
    XCloseDisplay(display);

    return 0;
}