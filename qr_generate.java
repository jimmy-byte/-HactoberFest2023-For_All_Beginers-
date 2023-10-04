import net.glxn.qrgen.core.image.ImageType;
import net.glxn.qrgen.javase.QRCode;

import java.io.File;
import java.io.IOException;

public class QRCodeGenerator {
    public static void main(String[] args) {
        String textToEncode = "Hello, QR Code!"; // Replace with your content

        // Generate QR code
        File qrCodeFile = QRCode.from(textToEncode)
            .withSize(250, 250) // Set the size of the QR code
            .to(ImageType.PNG)
            .file();

        // Print the location of the generated QR code
        System.out.println("QR code saved to: " + qrCodeFile.getAbsolutePath());
    }
}
