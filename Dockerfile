FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY CMakeLists.txt .
COPY src ./src

RUN mkdir build && cd build && \
    cmake .. -DBUILD_TESTS=OFF && \
    cmake --build . --target my_app


FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

RUN useradd --create-home appuser

WORKDIR /home/appuser

COPY --from=builder /app/build/my_app .

USER appuser

CMD ["./my_app"]
