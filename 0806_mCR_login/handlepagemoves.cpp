#include "handlepagemoves.h"

handlePageMoves::handlePageMoves()
{

}

void handlePageMoves::goToNextPage()
{
    EUHistory historyPage;
    int pageNow = historyPage.getCurrentPage();
    int pageTo = pageNow + 1;
    historyPage.setMovingToPage(pageTo);
    historyPage.printEUHistory(1);
}
