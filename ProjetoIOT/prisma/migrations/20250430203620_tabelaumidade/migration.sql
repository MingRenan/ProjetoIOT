-- CreateTable
CREATE TABLE "Umidade" (
    "id" SERIAL NOT NULL,
    "umidade" DOUBLE PRECISION NOT NULL,
    "dataHora" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT "Umidade_pkey" PRIMARY KEY ("id")
);
