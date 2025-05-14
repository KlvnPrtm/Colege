import java.awt.image.BufferedImage
import javax.imageio.ImageIO
import java.io.File

File baselineImage = new File('path_to_baseline_image.png')
File currentImage = new File('path_to_current_image.png')

BufferedImage img1 = ImageIO.read(baselineImage)
BufferedImage img2 = ImageIO.read(currentImage)

// Bandingkan ukuran gambar
assert img1.width == img2.width
assert img1.height == img2.height

// Bandingkan piksel per piksel
for (int y = 0; y < img1.height; y++) {
    for (int x = 0; x < img1.width; x++) {
        assert img1.getRGB(x, y) == img2.getRGB(x, y)
    }
}
