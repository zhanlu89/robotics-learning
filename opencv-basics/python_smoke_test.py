from pathlib import Path

import cv2
import numpy as np


OUTPUT_PATH = Path(__file__).resolve().parent / "output" / "python_smoke_test.png"
EXPECTED_SHAPE = (240, 320, 3)


def main() -> None:
    OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)

    image = np.full(EXPECTED_SHAPE, (32, 32, 32), dtype=np.uint8)
    cv2.rectangle(image, (40, 45), (280, 195), (0, 180, 255), thickness=4)
    cv2.putText(
        image,
        "OpenCV 4.6.0",
        (62, 128),
        cv2.FONT_HERSHEY_SIMPLEX,
        0.8,
        (255, 255, 255),
        thickness=2,
        lineType=cv2.LINE_AA,
    )

    if not cv2.imwrite(str(OUTPUT_PATH), image):
        raise RuntimeError(f"Failed to write {OUTPUT_PATH}")

    loaded = cv2.imread(str(OUTPUT_PATH), cv2.IMREAD_COLOR)
    if loaded is None:
        raise RuntimeError(f"Failed to read {OUTPUT_PATH}")
    if loaded.shape != EXPECTED_SHAPE:
        raise RuntimeError(
            f"Unexpected image shape: {loaded.shape}; expected {EXPECTED_SHAPE}"
        )

    print(f"OpenCV version: {cv2.__version__}")
    print(f"OpenCV module: {cv2.__file__}")
    print(f"Output: {OUTPUT_PATH}")
    print(f"Verified shape: {loaded.shape}")


if __name__ == "__main__":
    main()
