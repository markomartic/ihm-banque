#include "mongraphe.h"

MonGraphe::MonGraphe(QCustomPlot *customPlot, bool darkmode, int nbgraphs, QString sfirst, QString ssecond, QString sthird, int ifirst, int isecond, int ithird)
{
    if(darkmode) {
        QLinearGradient gradient(0, 0, 0, 400);
        gradient.setColorAt(0, QColor(90, 90, 90));
        gradient.setColorAt(0.38, QColor(105, 105, 105));
        gradient.setColorAt(1, QColor(70, 70, 70));
        customPlot->setBackground(QBrush(gradient));
        customPlot->xAxis->setBasePen(QPen(Qt::white));
        customPlot->xAxis->setTickPen(QPen(Qt::white));
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        customPlot->xAxis->setTickLabelColor(Qt::white);
        customPlot->xAxis->setLabelColor(Qt::white);

        customPlot->yAxis->setBasePen(QPen(Qt::white));
        customPlot->yAxis->setTickPen(QPen(Qt::white));
        customPlot->yAxis->setSubTickPen(QPen(Qt::white));
        customPlot->yAxis->grid()->setSubGridVisible(true);
        customPlot->yAxis->setTickLabelColor(Qt::white);
        customPlot->yAxis->setLabelColor(Qt::white);
        customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
        customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    } else {
        customPlot->setBackground(QBrush(QColor("#ededed")));
        customPlot->xAxis->setBasePen(QPen(Qt::black));
        customPlot->xAxis->setTickPen(QPen(Qt::black));
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        customPlot->xAxis->setTickLabelColor(Qt::black);
        customPlot->xAxis->setLabelColor(Qt::black);

        customPlot->yAxis->setBasePen(QPen(Qt::black));
        customPlot->yAxis->setTickPen(QPen(Qt::black));
        customPlot->yAxis->setSubTickPen(QPen(Qt::black));
        customPlot->yAxis->grid()->setSubGridVisible(true);
        customPlot->yAxis->setTickLabelColor(Qt::black);
        customPlot->yAxis->setLabelColor(Qt::black);
        customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
        customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    }

    QCPBars *qfirst = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *qsecond = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *qthird = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> qthirdData, qsecondData, qfirstData;

    qthird->setAntialiased(false);
    qthird->setStackingGap(1);
    qthird->setName("Prêts");
    qthird->setPen(QPen(QColor(0, 168, 140).lighter(170)));
    qthird->setBrush(QColor(0, 168, 140));
    ticks << 1;
    labels << sfirst;

    if(nbgraphs > 1) {

        qsecond->setAntialiased(false);
        qsecond->setStackingGap(1);
        qsecond->setName("Comptes");
        qsecond->setPen(QPen(QColor(250, 170, 20).lighter(150)));
        qsecond->setBrush(QColor(250, 170, 20));
        ticks << 2;
        labels << ssecond;
    }

    if(nbgraphs > 2) {
        qfirst->setAntialiased(false);
        qfirst->setStackingGap(1);
        qfirst->setName("Bourse");
        qfirst->setPen(QPen(QColor(0, 168, 140).lighter(130)));
        qfirst->setBrush(QColor(0, 168, 140));
        ticks << 3;
        labels << sthird;
    }

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(10);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, nbgraphs+1);
    customPlot->xAxis->setRange(0, nbgraphs+1);
    QFont pfont("Arial", 9);
    customPlot->xAxis->setTickLabelFont(pfont);

    // prepare y axis:
    int max = ifirst>isecond?ifirst:isecond;
    max = max>ithird?max:ithird;

    customPlot->yAxis->setRange(0, max);
    customPlot->yAxis->setPadding(1); // a bit more space to the left border
    customPlot->yAxis->setLabel("");

    // Add data:

    qthirdData  << ifirst << 0 << 0;
    qthird->setData(ticks, qthirdData);

    if(nbgraphs > 1) {
        qsecondData << 0 << isecond << 0;
        qsecond->setData(ticks, qsecondData);
    }

    if(nbgraphs > 2) {
        qfirstData  << 0 << 0 << ithird;
        qfirst->setData(ticks, qfirstData);
    }
}
