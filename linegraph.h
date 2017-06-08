#include "linegraph.h"
#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QTimer>
#include <QDebug>

//list of points in graph
QPolygonF points;
//number of times points have been added to the graph
int timesOff = 0;

QwtPlot *myPlot;
QwtPlotCurve *myCurve;

lineGraph::lineGraph(QwtPlot *plot, QWidget *parent) :
    QMainWindow(parent)
{
    myPlot = plot;


    //basic setup
   // QwtPlot plot;
    plot->setTitle( "Plot Demo" );
    plot->setCanvasBackground( Qt::white );
    plot->setAxisScale( QwtPlot::yLeft, 0.0, 10.0);
    plot->insertLegend( new QwtLegend() );

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( plot );

    //properties of the line
    QwtPlotCurve *curve = new QwtPlotCurve();
    myCurve=curve;
    curve->setTitle( "Pixel Count" );
    curve->setPen( Qt::black, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    //properties of points
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::red ), QPen( Qt::black, 2 ), QSize( 8, 8 ) );
    curve->setSymbol( symbol );


    curve->setSamples( points );


    //final setting up/ showing
    curve->attach( plot );

    //size of plot window
    plot->resize( 600, 400 );


}

//adds the next point to the graph and then updates it
void lineGraph::myCreatePoint() {

    //add point
    points<<QPointF(timesOff, 5);

    //updating
    myCurve->setSamples( points );
    myPlot->replot();
    timesOff++;



    //myCurve->attach( myPlot );
    //myPlot->resize(700,500);
    //myPlot->updateGeometry();
    //myPlot->update();
    //myPlot->updateAxes();
   //< myCurve->draw((myCurve->dataSize()-1),1-1);
   // qDebug()<< "test"<<points;
}

